#!/usr/bin/env bash
set -euo pipefail

script_dir=$(dirname $(readlink -f ${BASH_SOURCE[0]}))

set -x
mkdir -p $script_dir/zig-out

#zig run uhscrape.zig -- $script_dir/zig-out/uh.json $script_dir/headers/*
zig run $script_dir/uhscrape.zig -- $script_dir/zig-out/uh.json $script_dir/headers/x86_64-linux-gnu.2.36

rm -rf $script_dir/zig-out/uh
zig run $script_dir/uh.zig -- $script_dir/zig-out/uh.json $script_dir/zig-out/uh

zig cc $script_dir/test/hello.c -nostdinc -nostdlib -I$script_dir/zig-out/uh
