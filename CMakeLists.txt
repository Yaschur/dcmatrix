cmake_minimum_required(VERSION 3.14)

project(dcmatrix)

add_library(
  facet3
  src/facet3/Facet3.cpp
)
target_include_directories(
  facet3 PUBLIC
  include/facet3
)

add_subdirectory(tools)

enable_testing()

add_executable(
  facet3UnitTests
  src/facet3/Facet3.test.cpp
)
target_link_libraries(
  facet3UnitTests
  facet3
  GTest::GTest
  GTest::Main
  GMock::GMock
  GMock::Main
)

add_test(
  test_all
  facet3UnitTests
)
