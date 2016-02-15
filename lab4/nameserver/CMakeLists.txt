cmake_minimum_required(VERSION 3.4)
project(nameserver)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES nstest.cc)
add_executable(nameserver ${SOURCE_FILES})