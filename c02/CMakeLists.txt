cmake_minimum_required(VERSION 3.23)
project(c02 C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(c02 argument.c)
