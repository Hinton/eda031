cmake_minimum_required(VERSION 3.4)
project(lab3)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES date_test.cc date.cc)
add_executable(lab3 ${SOURCE_FILES})