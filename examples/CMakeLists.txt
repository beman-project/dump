# SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

add_executable(beman.dump.examples.basic)
target_sources(beman.dump.examples.basic PRIVATE basic.cpp)
target_link_libraries(beman.dump.examples.basic beman::dump)

