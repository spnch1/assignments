cmake_minimum_required(VERSION 3.29)
project(pr7_new C)

set(CMAKE_C_STANDARD 11)

add_executable(pr7_new main.c
        src/include/function.h
        src/include/color.h
        src/condition.c
        src/validation.c
        src/calculation_data.c
        src/calculation.c
        src/misc.c
)