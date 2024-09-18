cmake_minimum_required(VERSION 3.29)
project(W2 C)

set(CMAKE_C_STANDARD 11)

add_executable(W2 main.c
        src/functions.c
        include/functions.h)
