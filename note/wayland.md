###### may

> some tools may be helpful for wayland.

```shell
cage - Kiosk compositor for Wayland
mako-notifier - lightweight notification daemon for Wayland compositors
mpv - video player based on MPlayer/mplayer2
wdisplays - graphical application for configuring displays in Wayland compositors
```

###### Reference

[Weston build Reference](https://blog.csdn.net/yangchao315/article/details/123189373?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522165226783816782395393907%2522%252C%2522scm%2522%253A%252220140713.130102334.pc%255Fall.%2522%257D&request_id=165226783816782395393907&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~first_rank_ecpm_v1~rank_v31_ecpm-3-123189373-null-null.142^v9^pc_search_result_cache,157^v4^control&utm_term=%E7%BC%96%E8%AF%91weston&spm=1018.2226.3001.4187)

[Wayland Reference](https://blog.csdn.net/qq_26056015/category_11559440.html)

###### depend

```shell
sudo apt install libxml2 libxml2-dev xdot xmlto libjpeg-dev libwebp-dev libsystemd-dev liblcms2-dev libegl-mesa0 libgbm-dev freerdp2-dev libx11-xcb-dev libxcb-composite0 libcolord-dev libgstreamer1.0-dev libgstreamer-plugins-base1.0-dev libpipewire-0.3-dev python3-pip
sudo apt-cache search xcb
sudo apt-cache search libx11-xcb
sudo apt-get install libx11-xcb-dev
sudo apt-get install meson
sudo apt-get install libinput-dev
sudo apt-get install git
git clone https://gitlab.freedesktop.org/wayland/weston.git
cd weston/
sudo apt-get install cmake
sudo apt-get install libxkbcommon-dev
sudo apt install libwayland-dev libegl1-mesa-dev libglm-dev wayland-protocols libwayland-bin extra-cmake-modules
sudo apt-get install libpixman-1-dev
sudo apt-get install libdrm-dev
sudo apt-get install libcairo2-dev
sudo apt-get install libdbus-1-dev
sudo apt-get install libseat-dev
sudo apt-get install libva-dev
sudo apt-get install libxcb-composite0-dev
sudo apt-get install libxcursor-dev
sudo apt-get install libcolord-dev
sudo apt-get install libgstreamer1.0-dev
meson build -Dremoting=false -Dpipewire=false -Ddemo-clients=false
ninja -C build/
cd build/clients
./weston-simple-egl
```

###### build log

```shell
meson build -Dremoting=false -Dpipewire=false -Ddemo-clients=false
The Meson build system
Version: 0.61.2
Source dir: /home/pi/weston
Build dir: /home/pi/weston/build
Build type: native build
Project name: weston
Project version: 10.0.90
C compiler for the host machine: cc (gcc 11.2.0 "cc (Ubuntu 11.2.0-19ubuntu1) 11.2.0")
C linker for the host machine: cc ld.bfd 2.38
Host machine cpu family: x86_64
Host machine cpu: x86_64
Found git repository at /home/pi/weston
Compiler for C supports arguments -Wmissing-prototypes: YES 
Compiler for C supports arguments -Wno-unused-parameter: YES 
Compiler for C supports arguments -Wno-shift-negative-value: YES 
Compiler for C supports arguments -Wno-missing-field-initializers: YES 
Compiler for C supports arguments -Wno-pedantic: YES 
Compiler for C supports arguments -Wundef: YES 
Compiler for C supports arguments -fvisibility=hidden: YES 
Header <sys/sysmacros.h> has symbol "major" : YES 
Checking for function "mkostemp" : YES 
Checking for function "strchrnul" : YES 
Checking for function "initgroups" : YES 
Checking for function "posix_fallocate" : YES 
Checking for function "memfd_create" : YES 
Has header "linux/sync_file.h" : YES 
Message: The default backend is drm
Found pkg-config: /usr/bin/pkg-config (0.29.2)
Run-time dependency xkbcommon found: YES 1.4.0
Run-time dependency wayland-server found: YES 1.20.0
Run-time dependency wayland-client found: YES 1.20.0
Run-time dependency pixman-1 found: YES 0.40.0
Run-time dependency libinput found: YES 1.20.0
Run-time dependency libevdev found: YES 1.12.1
Library m found: YES
Library dl found: YES
Run-time dependency libdrm found: YES 2.4.110
Run-time dependency threads found: YES
Message: Found libdrm with human format modifier support.
Program python3 found: YES (/usr/bin/python3)
WARNING: Python files installed by Meson might not be found by python interpreter.
 This warning can be avoided by setting "python.platlibdir" option.
WARNING: Python files installed by Meson might not be found by python interpreter.
 This warning can be avoided by setting "python.purelibdir" option.
Configuring version.h using configuration
Found pkg-config: /usr/bin/pkg-config (0.29.2)
Build-time dependency wayland-scanner found: YES 1.20.0
Program /usr/bin/wayland-scanner found: YES (/usr/bin/wayland-scanner)
Run-time dependency wayland-protocols found: YES 1.25
Run-time dependency cairo found: YES 1.16.0
Run-time dependency libpng found: YES 1.6.37
Found CMake: /usr/bin/cmake (3.22.1)
Run-time dependency pango found: NO (tried pkgconfig and cmake)
Run-time dependency pangocairo found: NO (tried pkgconfig and cmake)
Run-time dependency glib-2.0 found: YES 2.72.1
Run-time dependency libjpeg found: YES 2.1.2
Run-time dependency libwebp found: YES 1.2.2
Run-time dependency egl found: YES 1.5
Run-time dependency libsystemd found: YES 249
Run-time dependency dbus-1 found: YES 1.12.20
Run-time dependency libseat found: YES 0.6.4
Run-time dependency libudev found: YES 249
Run-time dependency lcms2 found: YES 2.12
Dependency egl found: YES 1.5 (cached)
Run-time dependency glesv2 found: YES 3.2
Dependency libudev found: YES 249 (cached)
Dependency libudev found: YES 249 (cached)
Run-time dependency gbm found: YES 22.0.1
Run-time dependency libva found: YES 1.14.0
Run-time dependency libva-drm found: YES 1.14.0
Dependency threads found: YES unknown (cached)
Run-time dependency freerdp2 found: YES 2.6.1
Run-time dependency winpr2 found: YES 2.6.1
Dependency wayland-client found: YES 1.20.0 (cached)
Run-time dependency wayland-cursor found: YES 1.20.0
Run-time dependency wayland-egl found: YES 18.1.0
Run-time dependency xcb found: YES 1.14
Run-time dependency xcb-shm found: YES 1.14
Run-time dependency x11 found: YES 1.7.5
Run-time dependency x11-xcb found: YES 1.7.5
Run-time dependency xcb-xkb found: NO (tried pkgconfig and cmake)
Run-time dependency xwayland found: NO (tried pkgconfig and cmake)
Dependency xcb found: YES 1.14 (cached)
Run-time dependency xcb-composite found: YES 1.14
Run-time dependency xcb-shape found: YES 1.14
Run-time dependency xcb-xfixes found: YES 1.14
Run-time dependency xcursor found: YES 1.2.0
Run-time dependency cairo-xcb found: YES 1.16.0
Dependency lcms2 found: YES 2.12 (cached)
Run-time dependency colord found: YES 1.4.6
Dependency glib-2.0 found: YES 2.72.1 (cached)
Run-time dependency gobject-2.0 found: YES 2.72.1
Dependency libsystemd found: YES 249 (cached)
Configuring weston.ini using configuration
Configuring weston.ini using configuration
Dependency wayland-cursor found: YES 1.20.0 (cached)
Library util found: YES
Dependency libudev found: YES 249 (cached)
Dependency gbm found: YES 22.0.1 (cached)
Dependency egl found: YES 1.5 (cached)
Dependency glesv2 found: YES 3.2 (cached)
Dependency gbm found: YES 22.0.1 (cached)
Dependency egl found: YES 1.5 (cached)
Dependency glesv2 found: YES 3.2 (cached)
Dependency gbm found: YES 22.0.1 (cached)
Dependency egl found: YES 1.5 (cached)
Dependency wayland-egl found: YES 18.1.0 (cached)
Dependency glesv2 found: YES 3.2 (cached)
Dependency wayland-cursor found: YES 1.20.0 (cached)
Dependency wayland-cursor found: YES 1.20.0 (cached)
Dependency cairo found: YES 1.16.0 (cached)
Dependency cairo found: YES 1.16.0 (cached)
Dependency cairo found: YES 1.16.0 (cached)
Dependency libudev found: YES 249 (cached)
Run-time dependency libxml-2.0 found: YES 2.9.13
Dependency lcms2 found: YES 2.12 (cached)
Dependency x11 found: YES 1.7.5 (cached)
Configuring test-config.h using configuration
Dependency libudev found: YES 249 (cached)
Configuring weston.1 using configuration
Configuring weston-bindings.7 using configuration
Configuring weston-debug.1 using configuration
Configuring weston.ini.5 using configuration
Configuring weston-drm.7 using configuration
Configuring weston-rdp.7 using configuration
Configuring config.h using configuration
Message: Documentation will not be built. Use -Ddoc to build it.
Build targets in project: 168
NOTICE: Future-deprecated features used:
 * 0.56.0: {'Dependency.get_pkgconfig_variable'}

weston 10.0.90

  User defined options
    demo-clients: false
    pipewire    : false
    remoting    : false

Found ninja-1.10.1 at /usr/bin/ninja
```

###### Wayland

```c
/* 
	wl_shm_interface.name
*/
```

