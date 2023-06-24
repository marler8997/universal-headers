# The Universal Headers Project

** STATUS: VAPORWARE **

This project distributes a set of C headers (.h files) that are compatible with
widely used libcs for various targets.

Instead of copy+pasting N different libc header files, and requiring the use of
`-I` in C compiler invocations, this repository provides cleaned up headers
which use the C preprocessor in order to automatically support different targets
with the same set of includes.

The main purpose of this project is for simplicity and smaller installation size
for the use case of cross-compiling.

In the context of Zig, this project exists to facilitate
[ziglang/zig#2879](https://github.com/ziglang/zig/issues/2879).
Idea being that the end-result we want to eventually accomplish, is a set of
multi-target C headers (this project) plus implementations of the functions in
Zig. The C headers from this project would be periodically synchronized into the
Zig repository upstream.

The files are in `include/`. Everything else in this repository exists to aid
the creation and maintenance of those files.

## Strategy

C headers can be broken down into these fundamental operations:

    1. Define (or Undefine) preprocessor macro symbols
    2. Define types
    3. Define functions
    4. Provide (or don't provide) content for #include <PATH> or #include "PATH"

This set of operations gives us the criteria we need to verify our universal headers
are correct. Namely,

    is the set of macros/types/functions the same after every "include" directive
    between the universal headers and the original?

As far as I know, a tool that can verify this criteria doesn't exist yet.  Trying
to leverage existing C toolchains for this would require introspection into the
compiler state which I've never heard of, but, I don't think it would take much
effort to create a tool for this based on arocc.

I'd like to test our universal headers behave exactly the same as the original
leveraging existing build tools.  To do this, we can create a C compiler wrapper
that will forward the command to a real C compiler, but before doing so, also processes
the file and exports this compiler state.

### Provide (or don't provide) content for #include <PATH> or #include "PATH"

Toolchains control this behavior with the existence of files within an
include directory.  For universal headers, one strategy is to include every
possible file and emulate non-existence by leveraging `#include_next`.

## Stuff to save from original strategy section

Some preprocessor defines are already present to communicate the target; for
example the presence of `_WIN32` can be used to detect the Windows operating
system. However others are not available; for example there is no preprocessor
definition available to detect the difference between gnu or musl ABI. So this
project needs to define some custom preprocessor macros that can be used this
way.

We may want to look into automating this by parsing .h files and intelligently,
using type information, determine what is the same and what is different per
target, and then generate the .h files based on this information. Then this
repository would have a set of headers as inputs, and a set of headers as
outputs. The idea would be that the outputs would be fewer size in bytes
because of deduplication, support all the targets without any `-I` flags
needing to be different because of preprocessor usage, and the update process
would look like copy+pasting new versions of upstream headers into the input
headers, and then re-running the processing step.

This will reduce the effort needed to add support for more libcs, as well as
keep the installation size of the headers small, even as the number of
supported targets grows large.

## Desired Targets

 * [Mingw-w64](http://mingw-w64.org/) Headers
   - x86_64-windows-gnu
   - i386-windows-gnu
   - aarch64-windows-gnu
   - arm-windows-gnu
 * [Musl](http://musl.libc.org/) Headers
   - x86_64-linux-musl
   - i386-linux-musl
   - aarch64-linux-musl
   - arm-linux-musl
   - mips64-linux-musl
   - mips-linux-musl
   - powerpc64-linux-musl
   - powerpc-linux-musl
   - riscv64-linux-musl
   - s390x-linux-musl
 * [glibc](https://www.gnu.org/software/libc/) Headers
   - x86_64-linux-gnu
   - x86_64-linux-gnux32
   - i386-linux-gnu
   - aarch64-linux-gnu
   - aarch64_be-linux-gnu
   - arm-linux-gnueabi
   - arm-linux-gnueabihf
   - armeb-linux-gnueabi
   - armeb-linux-gnueabihf
   - csky-linux-gnueabi
   - csky-linux-gnueabihf
   - mips-linux-gnu
   - mips64-linux-gnuabi64
   - mips64-linux-gnuabin32
   - mips64el-linux-gnuabi64
   - mips64el-linux-gnuabin32
   - mipsel-linux-gnu
   - powerpc-linux-gnu
   - powerpc64-linux-gnu
   - powerpc64le-linux-gnu
   - riscv64-linux-gnu
   - s390x-linux-gnu
   - sparc-linux-gnu
   - sparcv9-linux-gnu
 * MacOS
   - x86_64-macos.10-none
   - x86_64-macos.11-none
   - x86_64-macos.12-none
   - aarch64-macos.11-none
   - aarch64-macos.12-none
 * Not associated with any particular implementation:
   - wasm-wasi-musl
   - wasm-freestanding-musl
 * FreeBSD
 * NetBSD
 * DragonFlyBSD
 * OpenBSD
 * Fuchsia
 * Haiku
 * Freestanding

## License

This project is MIT (Expat) licensed. It will contained derived work from
various other licenses:
 
 * Public Domain
 * APSL
