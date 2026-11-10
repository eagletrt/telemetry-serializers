# telemetry-serializers

Protobuf definitions shared by the telemetry services. The repository only
contains the `.proto` files: it is used as a git submodule, and every project
generates the code it needs outside of it, with the generator image
[`ghcr.io/eagletrt/serializers`](https://github.com/eagletrt/serializers).

## Using it in a project

Add the submodule and pin it to a tag:

```sh
git submodule add git@github.com:eagletrt/telemetry-serializers.git lib/external/serializers
cd lib/external/serializers && git checkout v1.0.0 && cd -
```

### Generate locally

Docker is the only requirement:

```sh
make -C lib/external/serializers generate
```

The code is written in `generate/`, in the root of **your project** (not inside
the submodule). Add `generate/` to your `.gitignore`. Other targets:

| Command | What it does |
|---|---|
| `make -C lib/external/serializers generate` | generates the code into `<project root>/generate` |
| `make -C lib/external/serializers check` | generates, compiles the protos and runs the generated tests |
| `make -C lib/external/serializers lint` | runs `buf lint` |
| `make -C lib/external/serializers clean` | removes the generated files (files you added stay) |

`OUT=some/dir` changes the output folder: a relative path is relative to the
root of your project, not to the submodule. `generate` refuses a non-empty
folder that it did not create, so pointing `OUT` at the wrong place cannot
overwrite your files; `FORCE=1` writes into it anyway. Only the files listed in
`.serializers-manifest` (the ones a previous run wrote) are ever deleted. The
generator version is the one in `SERIALIZERS_VERSION`.

### Generate in the service's Docker build

```dockerfile
# Required: without --build-arg the build fails with "invalid reference format".
ARG SERIALIZERS_VERSION
FROM ghcr.io/eagletrt/serializers:${SERIALIZERS_VERSION} AS codegen
COPY lib/external/serializers/proto /in
RUN generate --out /out

FROM python:3.12-slim
COPY --from=codegen /out /app/generated
```

Pass the version from the submodule, so it is defined in one place only:

```sh
docker build --build-arg SERIALIZERS_VERSION=$(cat lib/external/serializers/SERIALIZERS_VERSION) .
```

The submodule must be checked out in the build context: in CI, use
`actions/checkout` with `submodules: true` (or `recursive`).

The wrappers stay in each project; only the generated code is outside the
submodule.

## Supported systems

Everything runs in Docker, so what matters is the host that runs `make` and
`docker`:

| System | `make generate` |
|---|---|
| Linux (Ubuntu, Debian, ...), x86_64 and ARM | yes |
| macOS, Intel and Apple Silicon | yes (the image has both variants) |
| Windows with WSL2 (Ubuntu), run the commands inside WSL | yes, same as Linux |
| Windows without WSL | use the `docker run` command below |
| Linux with SELinux (Fedora, RHEL) | `make generate SELINUX=1` |

On Windows without `make`, from PowerShell in the root of your project:

```powershell
$v = (Get-Content lib/external/serializers/SERIALIZERS_VERSION).Trim()
docker run --rm `
  -v "${PWD}/lib/external/serializers/proto:/in:ro" `
  -v "${PWD}/generate:/out" `
  ghcr.io/eagletrt/serializers:$v generate
```

Docker Desktop (Windows, macOS) or Docker Engine (Linux) is required. If the
repository is checked out on Windows, `.gitattributes` keeps the line endings
as LF; do not override it.

## Versions

- This repository is versioned with semver tags (`v1.2.0`). Projects pin the
  submodule to a tag. A change that removes or renumbers a field is a major
  version.
- These tags version the **protos**; `SERIALIZERS_VERSION` versions the
  **generator image** (the tags of `eagletrt/serializers`). The two numbers
  are independent, even if both start at `1.0.0`.
- Releasing: after merging into `main`, tag the merge commit and push the tag
  (`git tag v1.3.0 && git push origin v1.3.0`). A pull request merged with the
  `buf skip breaking` label requires a new major version.
- `SERIALIZERS_VERSION` holds the version of the generator image that goes with
  these protos. It is the only place where it is written: the Makefile and the
  CI read it from there. To upgrade the generator, change that file in a pull
  request.

## Checks

`.github/workflows/validate.yaml` runs on every pull request and on pushes to
`main` and `dev`:

- `buf lint`, with the rules in `buf.yaml`;
- `buf breaking` against the base branch (pull requests). For an intentional
  breaking change add the `buf skip breaking` label to the pull request.
  The first pull requests that bring `buf.yaml` into a branch (into `dev`,
  then into `main`) need the label too: the base branch has no `buf.yaml`, so
  every file looks moved from `proto/x.proto` to `x.proto`;
- the generator image in `check` mode: it generates the code, compiles the
  protos and runs the generated tests.

Nothing is published. The same checks run locally with `make lint` and
`make check`.

## Legacy branches

`generation.yaml` and `dev_generation.yaml` still publish the generated code on
the `build` and `dev-build` branches, for the projects that have not migrated
yet. Once nobody uses them, delete the two workflows and the branches.
