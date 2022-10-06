cmake_minimum_required(VERSION 3.23)
project(c03 C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(c03 rand.c)
