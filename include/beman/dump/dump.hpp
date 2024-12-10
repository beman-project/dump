// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef BEMAN_DUMP_DUMP_HPP_INCLUDED
#define BEMAN_DUMP_DUMP_HPP_INCLUDED

#include <array>
#include <functional>
#include <print>
#include <string_view>

namespace beman::dump {
namespace detail {
// TODO: Need documentation
template <std::size_t N>
constexpr auto format_string = std::invoke([] {
  std::array<char, N * 3 - 1> result{};

  auto ptr = &result[0];
  for (auto i = 0uz; i != N; ++i) {
    if (i > 0)
      *ptr++ = ' ';
    *ptr++ = '{';
    *ptr++ = '}';
  }

  return result;
});

template <> inline constexpr std::array<char, 0> format_string<0>;
} // namespace detail

// TODO: Need documentation
template <typename... Args> void dump(Args &&...args) {
  std::println(std::string_view(detail::format_string<sizeof...(Args)>),
               std::forward<Args>(args)...);
}
} // namespace beman::dump

#endif // BEMAN_DUMP_DUMP_HPP_INCLUDED
