cmake_minimum_required(VERSION 3.12.4)
project(lps25hb VERSION 0.1.0)

add_executable(lps25hb main.c)

find_package(PkgConfig)
pkg_check_modules(IIO libiio)


include_directories(${IIO_INCLUDE_DIRS})
link_directories(${IIO_LIBRARY_DIRS})

target_link_libraries(lps25hb ${IIO_LIBRARIES})
