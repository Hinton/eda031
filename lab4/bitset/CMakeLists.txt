cmake_minimum_required(VERSION 3.4)
project(bitset)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES bitsettest2.cc bitset.cc bitreference.cc)
add_executable(bitset ${SOURCE_FILES})