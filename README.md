<!--
SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
-->

# beman.dump: Implementation of proposed `std::dump`

![Continuous Integration Tests](https://github.com/beman-project/dump/actions/workflows/ci_tests.yml/badge.svg)

`std::dump` prints its arguments space-separated with a new-line.
A call to `std::dump(arg1, arg2, …, argn)` is equivalent to `std::println(“{} {} … {}”, arg1, arg2, …, argn)`

`std::dump` is proposed by [P2879](https://wg21.link/P2879). This project currently implements R0.

## Building beman.dump

### Dependencies
<!-- TODO Darius: rewrite section!-->

This project has no C or C++ dependencies.

Build-time dependencies:

- `cmake`
- `ninja`, `make`, or another CMake-supported build system
  - CMake defaults to "Unix Makefiles" on POSIX systems

#### How to install dependencies

<!-- TODO Darius: rewrite section!-->

<details>
<summary>Dependencies install example on Ubuntu 24.04  </summary>

<!-- TODO Darius: rewrite section!-->

```shell
# Install tools:
apt-get install -y cmake make ninja-build

# Toolchains:
apt-get install                           \
  g++-14 gcc-14 gcc-13 g++-14             \
  clang-18 clang++-18 clang-17 clang++-17
```

</details>

<details>
<summary>Dependencies install example on MAC OS $VERSION </summary>

<!-- TODO Darius: rewrite section!-->
```shell
# TODO
```

</details>

<details>
<summary>Dependencies install example on Windows $VERSION  </summary>
<!-- TODO Darius: rewrite section!-->

```shell
# TODO
```

</details>

### How to build beman.dump

This project strives to be as normal and simple a CMake project as possible. This build workflow in particular will work, producing a static `libbeman.dump.a` library, ready to package with its headers:

```shell
cmake -B build -S .
cmake --build build
ctest --test-dir build
cmake --install build --prefix /opt/beman.dump
```
## Integrate beman.dump into your project

<details>
<summary> Use beman.dump directly from C++ </summary>
<!-- TODO Darius: rewrite section!-->

If you want to use `beman.dump` from your project, you can include `beman/dump/*.hpp`  files from your C++ source files

```cpp
#include <beman/dump/identity.hpp>
```

and directly link with `libbeman.dump.a`

```shell
# Assume /opt/beman.dump staging directory.
$ c++ -o basic examples/basic.cpp \
    -I /opt/beman.dump/include/ \
    -L/opt/beman.dump/lib/ -lbeman.dump
```

</details>

<details>
<summary> Use beman.dump directly from CMake </summary>

<!-- TODO Darius: rewrite section! Add examples. -->

For CMake based projects, you will need to use the `beman.dump` CMake module to define the `beman::dump` CMake target:

```cmake
find_package(beman.dump REQUIRED)
```

You will also need to add `beman::dump` to the link libraries of any libraries or executables that include `beman/dump/*.hpp` in their source or header file.

```cmake
target_link_libraries(yourlib PUBLIC beman::dump)
```

</details>

<details>
<summary> Use beman.dump from other build systems </summary>

<!-- TODO Darius: rewrite section! Add examples. -->

Build systems that support `pkg-config` by providing a `beman.dump.pc` file. Build systems that support interoperation via `pkg-config` should be able to detect `beman.dump` for you automatically.

</details>

## Contributing

Please do! Issues and pull requests are appreciated.
