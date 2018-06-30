cmake_minimum_required(VERSION 2.8)
project(spellchecker)
set(CMAKE_CXX_STANDARD 14)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)


include_directories(${CMAKE_SOURCE_DIR}/include)

add_library(fuzzysearch include/spellchecker/spellchecker.h  src/spellchecker.cpp)

add_executable(${PROJECT_NAME} src/main.cpp)
target_link_libraries(spellchecker fuzzysearch)

# Setup testing
enable_testing()
find_package(GTest REQUIRED)
message(STATUS "Found GTest " ${GTEST_FOUND})
include_directories(${GTEST_INCLUDE_DIR})

add_subdirectory(tests)
