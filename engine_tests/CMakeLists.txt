cmake_minimum_required(VERSION 3.10)
project(engine_tests VERSION 1.0)

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include(FetchContent)

FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG release-1.11.0
)
FetchContent_MakeAvailable(googletest)

# Add source files from the tests folder
file(GLOB_RECURSE TEST_SOURCES tests/*.cpp)

# Create the test executable
add_executable(${PROJECT_NAME} ${TEST_SOURCES})

# Link against engine_lib and GoogleTest
target_link_libraries(${PROJECT_NAME} PRIVATE engine_lib gtest gtest_main)

# Include directories
target_include_directories(${PROJECT_NAME} PRIVATE tests ${gtest_SOURCE_DIR}/include ${CMAKE_CURRENT_SOURCE_DIR}/../engine_lib/src)

# Add tests
add_test(NAME engine_lib_gtest COMMAND ${PROJECT_NAME})