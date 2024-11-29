cmake_minimum_required(VERSION 3.10)
project(NetworkOptimizer)

# Opciones de compilación
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Habilitar testing
enable_testing()

# Agregar Google Test
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.13.0.zip
)
FetchContent_MakeAvailable(googletest)

# Crear la biblioteca principal
add_library(network_lib
    src/NetworkOptimizer.cpp
)
target_include_directories(network_lib PUBLIC include)

# Crear el ejecutable principal
add_executable(network_optimizer src/main.cpp)
target_link_libraries(network_optimizer PRIVATE network_lib)

# Crear y configurar los tests
add_executable(network_tests test/test_network.cpp)
target_link_libraries(network_tests
    PRIVATE
    network_lib
    gtest_main
)

# Agregar los tests al CTest
include(GoogleTest)
gtest_discover_tests(network_tests)