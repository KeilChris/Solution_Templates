[![Version](https://img.shields.io/github/v/release/KeilChris/Blinky_Templates)](https://github.com/KeilChris/Blinky_Templates/releases/latest)
[![License: Apache-2.0](https://img.shields.io/badge/License-Apache--2.0-green?label)](https://github.com/KeilChris/Blinky_Templates/blob/main/LICENSE)

# Template CMSIS Solutions

This repository contains three CMSIS solution templates that can be used to setup either a blank or two simple Blinky projects.

## Repository top-level structure

Directory                   | Description
:---------------------------|:--------------
[.github/workflows](https://github.com/KeilChris/Blinky_Templates/tree/main/.github/workflows)  | [GitHub Actions](#github-actions) for creating the software pack.
[Templates](https://github.com/KeilChris/Blinky_Templates/tree/main/Templates)                  | Generic project templates to start new *csolution projects*.
[Docs](https://github.com/KeilChris/Blinky_Templates/tree/main/Docs)                            | `Overview.md` file for the software pack.

## Usage

The `README.md` files for each project template explain the usage.

## Using the development repository

This development repository can be used in a local directory and
[mapped as software pack](https://open-cmsis-pack.github.io/cmsis-toolbox/build-tools/#install-a-repository) using for
example `cpackget` with:

```sh
cpackget add <path>/KeilChris.Solution_Templates.pdsc
```

## Generate software pack

The software pack is generated using bash shell scripts. [`./gen_pack.sh`](./gen_pack.sh) based on
[Open-CMSIS-Pack/gen-pack]( https://github.com/Open-CMSIS-Pack/gen-pack)) generates the software pack. Run this script
locally with:

```sh
$ ./gen_pack.sh
```

### GitHub Actions

The repository uses GitHub Actions to generate the pack. The `.github/workflows/pack.yml` is based on
[Open-CMSIS-Pack/gen-pack-action](https://github.com/Open-CMSIS-Pack/gen-pack-action) and generates pack using the
[Generate software pack](#generate-software-pack) scripts.

## Issues

Please feel free to raise an [issue on GitHub](https://github.com/KeilChris/Solution_Templates/issues)
to report misbehavior (i.e. bugs) or start discussions about enhancements. This
is your best way to interact directly with the maintenance team and the community.
We encourage you to append implementation suggestions as this helps to decrease the
workload of the maintenance team.
