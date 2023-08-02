
## Setup

This demo uses [gRPC](https://grpc.io/) with [Protocol Buffers](https://protobuf.dev/). Nix is employed as the package manager [Install Nix.](https://nixos.org/download.html)

## Building

Enter Nix shell, this will put all required dependencies in your path:

```sh
$ nix-shell
```

Build:

```sh
$ meson setup build
$ cd build
$ meson compile
```

When ready two artifacts should appear: `server` and `client`, try running them.
