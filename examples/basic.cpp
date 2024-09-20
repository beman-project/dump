// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#include <beman/dump/dump.hpp>

int main()
{
    beman::dump::dump(42, "Hello World!", 3.14, nullptr);
}

