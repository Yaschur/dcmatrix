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
target_compile_options(
  facet3 PRIVATE
  -Wall -Weffc++ -Wextra -Wsign-conversion
)

add_library(
  dcmatrix
  src/dcmatrix/Dcmatrix.cpp
)
target_include_directories(
  dcmatrix PUBLIC
  include/dcmatrix
)
target_link_libraries(
  dcmatrix
  facet3
)
target_compile_options(
  dcmatrix PRIVATE
  -Wall -Weffc++ -Wextra -Wsign-conversion
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
target_compile_options(
  facet3UnitTests PRIVATE
  -Wall -Weffc++ -Wextra -Wsign-conversion
)

add_executable(
  dcmatrixUnitTests
  src/dcmatrix/Dcmatrix.test.cpp
)
target_link_libraries(
  dcmatrixUnitTests
  dcmatrix
  GTest::GTest
  GTest::Main
  GMock::GMock
  GMock::Main
)
target_compile_options(
  dcmatrixUnitTests PRIVATE
  -Wall -Weffc++ -Wextra -Wsign-conversion
)

add_test(
  test_facet
  facet3UnitTests
)
add_test(
  test_dcmatrix
  dcmatrixUnitTests
)
