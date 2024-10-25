cmake_minimum_required(VERSION 3.12.4)
project(acc VERSION 0.1.0)

add_executable(acc main.c)

find_package(PkgConfig)
pkg_check_modules(IIO libiio)


include_directories(${IIO_INCLUDE_DIRS})
link_directories(${IIO_LIBRARY_DIRS})

target_link_libraries(acc ${IIO_LIBRARIES} m)
