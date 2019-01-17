cmake_minimum_required(VERSION 3.13)
project(TestMyModule)

set(CMAKE_C_STANDARD 90)

# Create the test harness
add_executable(test_my_module test_my_module.c)
target_link_libraries(test_my_module my_module)

# Test the C Binary linked to the library `my_module`
add_test(NAME test_my_module COMMAND test_my_module)
# add_test(NAME test_my_module COMMAND "${CMAKE_COMMAND}" -E "${CMAKE_CURRENT_BINARY_DIR}/test_my_module")