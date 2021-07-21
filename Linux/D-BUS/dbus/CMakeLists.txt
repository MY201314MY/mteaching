cmake_minimum_required(VERSION 3.16)
project(dbus C)

INCLUDE_DIRECTORIES(/usr/include/dbus-1.0)
INCLUDE_DIRECTORIES(/usr/lib/x86_64-linux-gnu/dbus-1.0/include)

INCLUDE_DIRECTORIES(/usr/include/glib-2.0)
INCLUDE_DIRECTORIES(/usr/lib/x86_64-linux-gnu/glib-2.0/include)

INCLUDE_DIRECTORIES(/usr/include/gio-unix-2.0/)
INCLUDE_DIRECTORIES(/usr/include/glib-2.0 -I/usr/lib/x86_64-linux-gnu/glib-2.0/include)



set(CMAKE_C_STANDARD 99)

add_executable(dbus main.c gdbus.c)

target_link_libraries(dbus pthread dbus-1 gio-2.0 gobject-2.0 glib-2.0)
