cmake_minimum_required(VERSION 3.10)
project(NetworkOptimizer)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

enable_testing()

# Google Test
include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.13.0.zip
)
FetchContent_MakeAvailable(googletest)

# Tests
add_executable(network_tests test/test_network.cpp)
target_include_directories(network_tests PRIVATE include)
target_link_libraries(network_tests gtest_main)

include(GoogleTest)
gtest_discover_tests(network_tests)
