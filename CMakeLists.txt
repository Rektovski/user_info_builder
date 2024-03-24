cmake_minimum_required(VERSION 3.23)
project(untitled3)

set(CMAKE_CXX_STANDARD 17)

add_executable(untitled3 main.cpp
        cpp_format/build_user.cpp
        h_format/build_user.h
        cpp_format/build_user_helper.cpp
        h_format/build_user_helper.h
)
