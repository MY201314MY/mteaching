cmake_minimum_required(VERSION 3.12)
project(protobuf C)

set(CMAKE_C_STANDARD 99)

add_executable(protobuf main.c pb_common.c pb_encode.c pb_decode.c message.pb.c)