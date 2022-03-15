cmake_minimum_required(VERSION 3.21)
project(Matrix C)

set(CMAKE_C_STANDARD 99)

add_executable(Matrix main.c matrix/matrix.h matrix/matrix.c)
