cmake_minimum_required(VERSION 3.7)
project(02)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        include/Printf.h
        src/main.cpp
        src/Printf.cpp)

add_executable(02 ${SOURCE_FILES})