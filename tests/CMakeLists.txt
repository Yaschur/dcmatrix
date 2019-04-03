cmake_minimum_required(VERSION 3.14)

project(test)

set(SOURCES
    ../src/facet/Facet3.cpp
    test.cpp
)

add_executable(test ${SOURCES})

target_include_directories(test
  PRIVATE
    ${PROJECT_SOURCE_DIR}/../src/facet
)
