cmake_minimum_required(VERSION 3.13)
project(TestMySwig)

find_package(Python COMPONENTS Interpreter REQUIRED)

add_test(NAME test_my_swig
  COMMAND "${CMAKE_COMMAND}" -E env "PYTHONPATH=$<TARGET_FILE_DIR:my_swig>"
  "${Python_EXECUTABLE}" "${CMAKE_CURRENT_SOURCE_DIR}/test_my_swig.py")
