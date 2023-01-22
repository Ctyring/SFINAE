cmake_minimum_required(VERSION 3.22)
project(SFINAE)

set(CMAKE_CXX_STANDARD 11)

add_executable(SFINAE hasSerialize.h structData.h main.cpp)
