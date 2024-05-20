cmake_minimum_required(VERSION 3.28.1)
project(TETR_IO_Visulizer)

set(CMAKE_CXX_STANDARD 20)

include_directories(include/)

add_executable(TETR_IO_Visulizer main.cpp
        Parse.cpp
        Parse.h)
