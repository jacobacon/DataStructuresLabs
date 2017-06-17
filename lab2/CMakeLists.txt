cmake_minimum_required(VERSION 3.7)
project(lab2)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES charchain.cpp Node.cpp Node.h LinkedChar.cpp LinkedChar.h)
add_executable(lab2 ${SOURCE_FILES})