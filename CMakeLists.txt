cmake_minimum_required(VERSION 3.6)
project(drzewo2)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES solution.c tree.c tree.h list.c list.h)
add_executable(drzewo2 ${SOURCE_FILES})