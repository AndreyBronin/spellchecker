cmake_minimum_required(VERSION 2.8)
project(test_spellchecker)
set(CMAKE_CXX_STANDARD 14)


set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

#SET(COVERAGE ON CACHE BOOL "Coverage")

include_directories(${GTEST_INCLUDE_DIR})

add_executable (${PROJECT_NAME} spellchecker_test.cpp cyrillic_test.cpp)
target_link_libraries(${PROJECT_NAME} ${GTEST_BOTH_LIBRARIES} fuzzysearch)


add_test(NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME} --gtest_output=xml)

# Setup coverage
include(../CodeCoverage.cmake)
#set(COVERAGE_EXCLUDES 'tests/*')
APPEND_COVERAGE_COMPILER_FLAGS() 
SETUP_TARGET_FOR_COVERAGE(
     NAME ctest_coverage
     EXECUTABLE ctest -j ${PROCESSOR_COUNT}
     DEPENDENCIES test_spellchecker)