cmake_minimum_required(VERSION 3.12.4)
project(main VERSION 0.1.0)

set(CMAKE_C_COMPILER "/home/pi/opt/arm-gnu-toolchain-11.3.rel1-x86_64-arm-none-linux-gnueabihf/bin/arm-none-linux-gnueabihf-gcc")
set(CMAKE_CXX_COMPILER "/home/pi/opt/arm-gnu-toolchain-11.3.rel1-x86_64-arm-none-linux-gnueabihf/bin/arm-none-linux-gnueabihf-g++")

add_executable(main main.c)
