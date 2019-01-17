cmake_minimum_required(VERSION 3.13)
project(SwigExample C)

set(CMAKE_C_STANDARD 90)

enable_testing()

add_subdirectory(my_module)
add_subdirectory(my_swig)
add_subdirectory(tests)
