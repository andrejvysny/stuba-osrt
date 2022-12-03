cmake_minimum_required(VERSION 3.23)
project(c05 C)

set(CMAKE_C_STANDARD 11)

add_executable(c05
        chat_client.c
        chat_server.c server.c)
