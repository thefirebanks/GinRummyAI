cmake_minimum_required(VERSION 3.8)
project(TestingGin)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES cmake-build-debug/main.cpp)
add_executable(TestingGin ${SOURCE_FILES})