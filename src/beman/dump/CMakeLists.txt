# SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

add_library(beman.dump STATIC)
add_library(beman::dump ALIAS beman.dump)

target_sources(beman.dump PRIVATE dump.cpp)

target_include_directories(
  beman.dump
  PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../../../include>)
target_compile_features(
  beman.dump
  PUBLIC cxx_std_23)

install(
  TARGETS beman.dump
  EXPORT beman.dump
  DESTINATION ${CMAKE_INSTALL_LIBDIR})

install(
  DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/../../../include/
  DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
  FILES_MATCHING
  PATTERN "*.hpp")

if(BUILD_TESTING)
  include(GoogleTest)

  add_executable(beman.dump.tests)
  target_sources(beman.dump.tests PRIVATE dump.t.cpp)
  target_link_libraries(beman.dump.tests
                        PRIVATE beman::dump GTest::gtest GTest::gtest_main)

  gtest_add_tests(beman.dump.tests "" AUTO)
endif()
