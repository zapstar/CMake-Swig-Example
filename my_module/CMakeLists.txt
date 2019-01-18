cmake_minimum_required(VERSION 3.13)
project(MyModule)

set(CMAKE_C_STANDARD 90)

set(CMAKE_POSITION_INDEPENDENT_CODE ON)

add_library(my_module hash_table.c add.c sub.c)
target_include_directories(my_module
  # Within our library, if a header file `xyz.h` is present
  # in `include/my_module/` then you can include it by just
  # using `#include "xyz.h"`
  PRIVATE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/my_module>
          $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/my_module_int>
  # Consumers of this library will use `#include "my_module/xyz.h`
  PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>)
