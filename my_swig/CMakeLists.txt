cmake_minimum_required(VERSION 3.13)
project(MySwig)

set(CMAKE_C_STANDARD 90)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

find_package(SWIG REQUIRED)
find_package(Python COMPONENTS Development REQUIRED)

include(${SWIG_USE_FILE})
set(UseSWIG_TARGET_NAME_PREFERENCE STANDARD)
set(SWIG_USE_TARGET_INCLUDE_DIRECTORIES TRUE)

swig_add_library(my_swig LANGUAGE python SOURCES my_swig.i)
target_link_libraries(my_swig my_module Python::Python)
set_target_properties(my_swig PROPERTIES SWIG_USE_TARGET_INCLUDE_DIRECTORIES TRUE)
