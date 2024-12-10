// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#include <beman/dump/dump.hpp>

#include <gtest/gtest.h>

TEST(DumpTest, format_string)
{
    using beman::dump::detail::format_string;

    EXPECT_EQ(std::string_view(format_string<0>), "");
    EXPECT_EQ(std::string_view(format_string<1>), "{}");
    EXPECT_EQ(std::string_view(format_string<2>), "{} {}");
    EXPECT_EQ(std::string_view(format_string<3>), "{} {} {}");
}
