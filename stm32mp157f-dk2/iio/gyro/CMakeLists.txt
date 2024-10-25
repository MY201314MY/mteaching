cmake_minimum_required(VERSION 3.12.4)
project(gyro VERSION 0.1.0)

add_executable(gyro main.c)

find_package(PkgConfig)
pkg_check_modules(IIO libiio)


include_directories(${IIO_INCLUDE_DIRS})
link_directories(${IIO_LIBRARY_DIRS})

target_link_libraries(gyro ${IIO_LIBRARIES} m)
