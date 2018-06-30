cmake_minimum_required(VERSION 3.9)
project(test_spellchecker)
set(CMAKE_CXX_STANDARD 14)

include(GoogleTest)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)


include_directories(${GTEST_INCLUDE_DIR})

add_executable (${PROJECT_NAME} spellchecker_test.cpp cyrillic_test.cpp)
target_link_libraries(${PROJECT_NAME} ${GTEST_BOTH_LIBRARIES} fuzzysearch)

add_test(NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME} --gtest_output=xml)