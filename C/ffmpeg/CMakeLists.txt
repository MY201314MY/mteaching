cmake_minimum_required(VERSION 3.23)
project(ffmpeg C)

set(CMAKE_C_STANDARD 99)

find_package(PkgConfig)
pkg_check_modules(PKG_AV libavutil libavcodec libavformat libswscale libswresample)

add_executable(ffmpeg main.c)
target_link_libraries(ffmpeg ${PKG_AV_LIBRARIES})
