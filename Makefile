# Local helpers for telemetry-serializers. They run the generator in Docker, so
# the only requirement is Docker: no protoc, Go or Python to install.
#
#   make generate   generate the code into <project root>/generate
#   make check      generate, compile and run the generated tests
#   make lint       buf lint on the .proto files
#   make clean      remove the generated folder
#
# From a project that has this repository as a submodule:
#
#   make -C lib/external/serializers generate
#
# The code is written in the root of that project (the one that contains the
# submodule), in `generate/`. Override with OUT=/some/dir or IMAGE=...

SELF := $(dir $(abspath $(lastword $(MAKEFILE_LIST))))
VERSION := $(shell tr -d '[:space:]' < "$(SELF)SERIALIZERS_VERSION")
IMAGE ?= ghcr.io/eagletrt/serializers:$(VERSION)
BUF_IMAGE ?= bufbuild/buf:1.75.0

# Root of the project that contains this repository as a submodule; this
# repository's own root when it is used standalone.
SUPERPROJECT := $(shell git -C "$(SELF)" rev-parse --show-superproject-working-tree 2>/dev/null)
PROJECT_ROOT ?= $(if $(SUPERPROJECT),$(SUPERPROJECT),$(patsubst %/,%,$(SELF)))
OUT ?= $(PROJECT_ROOT)/generate

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

.PHONY: help pull generate check lint clean

help:
	@echo "generator image: $(IMAGE)"
	@echo "output folder:   $(OUT)"
	@echo
	@echo "make pull       download the generator image"
	@echo "make generate   generate the code into the output folder"
	@echo "make check      generate, compile and run the generated tests"
	@echo "make lint       buf lint on the .proto files"
	@echo "make clean      remove the output folder"

pull:
	docker pull $(IMAGE)

generate:
	mkdir -p "$(OUT)"
	$(DOCKER_RUN) -v "$(SELF)proto:/in:$(RO_MOUNT)" -v "$(OUT):/out:$(RW_MOUNT)" $(IMAGE) generate

check:
	$(DOCKER_RUN) -v "$(SELF)proto:/in:$(RO_MOUNT)" $(IMAGE) check

lint:
	docker run --rm -v "$(SELF):/workspace:$(RW_MOUNT)" -w /workspace $(BUF_IMAGE) lint

# Only a folder created by `make generate` (it holds a .serializers-version
# file) is removed, so a wrong OUT can never delete anything else.
clean:
	@if [ -e "$(OUT)/.serializers-version" ]; then rm -rf "$(OUT)" && echo "removed $(OUT)"; \
	else echo "nothing to clean in $(OUT)"; fi
