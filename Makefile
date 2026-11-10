# Local helpers for telemetry-serializers. They run the generator in Docker, so
# the only requirement is Docker: no protoc, Go or Python to install.
#
#   make generate   generate the code into <project root>/generate
#   make check      generate, compile and run the generated tests
#   make lint       buf lint on the .proto files
#   make clean      remove the generated files
#
# From a project that has this repository as a submodule:
#
#   make -C lib/external/serializers generate
#
# The code is written in the root of that project (the one that contains the
# submodule), in `generate/`. Override with OUT=dir (relative to that project
# root, or absolute) or IMAGE=... `generate` refuses a non-empty folder that it
# did not create; FORCE=1 writes into it anyway.

SELF := $(dir $(abspath $(lastword $(MAKEFILE_LIST))))
VERSION := $(shell tr -d '[:space:]' < "$(SELF)SERIALIZERS_VERSION")
IMAGE ?= ghcr.io/eagletrt/serializers:$(VERSION)
BUF_IMAGE ?= bufbuild/buf:1.75.0

# Root of the project that contains this repository as a submodule; this
# repository's own root when it is used standalone.
SUPERPROJECT := $(shell git -C "$(SELF)" rev-parse --show-superproject-working-tree 2>/dev/null)
PROJECT_ROOT ?= $(if $(SUPERPROJECT),$(SUPERPROJECT),$(patsubst %/,%,$(SELF)))
OUT ?= $(PROJECT_ROOT)/generate
# `make -C` runs in the submodule and Docker needs an absolute path (a relative
# one is taken as the name of a Docker volume): resolve OUT against the project
# root. Absolute paths (/x, and C:/x in Git Bash) are kept as they are.
override OUT := $(patsubst %/,%,$(if $(filter /% %:/%,$(OUT)),$(OUT),$(PROJECT_ROOT)/$(OUT)))

# Git Bash on Windows rewrites container paths such as /in into C:/Program
# Files/Git/in: turn that off (it has no effect on Linux and macOS).
export MSYS_NO_PATHCONV := 1

# Linux with SELinux enforcing (Fedora, RHEL): `make generate SELINUX=1` adds
# the :z label that bind mounts need. Not needed on Ubuntu, macOS or Windows.
ifdef SELINUX
RO_MOUNT := ro,z
RW_MOUNT := z
else
RO_MOUNT := ro
RW_MOUNT := rw
endif

# Run as the current user so the generated files are not owned by root.
DOCKER_RUN := docker run --rm --user $(shell id -u):$(shell id -g)
GENERATE_FLAGS := $(if $(FORCE),--force)

.PHONY: help pull generate check lint clean

help:
	@echo "generator image: $(IMAGE)"
	@echo "output folder:   $(OUT)"
	@echo
	@echo "make pull       download the generator image"
	@echo "make generate   generate the code into the output folder"
	@echo "make check      generate, compile and run the generated tests"
	@echo "make lint       buf lint on the .proto files"
	@echo "make clean      remove the generated files"

pull:
	docker pull $(IMAGE)

generate:
	mkdir -p "$(OUT)"
	$(DOCKER_RUN) -v "$(SELF)proto:/in:$(RO_MOUNT)" -v "$(OUT):/out:$(RW_MOUNT)" $(IMAGE) generate $(GENERATE_FLAGS)

check:
	$(DOCKER_RUN) -v "$(SELF)proto:/in:$(RO_MOUNT)" $(IMAGE) check

lint:
	docker run --rm -v "$(SELF):/workspace:$(RO_MOUNT)" -w /workspace $(BUF_IMAGE) lint

# Only the files that `make generate` wrote (listed in .serializers-manifest)
# are removed, by the generator image itself; files added to the folder stay.
# The folder is removed too if nothing else is left in it.
clean:
	@if [ -e "$(OUT)/.serializers-version" ]; then \
		$(DOCKER_RUN) -v "$(OUT):/out:$(RW_MOUNT)" $(IMAGE) clean && \
		{ rmdir "$(OUT)" 2>/dev/null || true; }; \
	else echo "nothing to clean in $(OUT)"; fi
