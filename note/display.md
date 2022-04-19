## Display

### Search

#### brightness

```shell
root@stm32mp1:/sys/devices/platform/soc/5a000000.dsi/backlight/5a000000.dsi.0# ls
actual_brightness  brightness  max_brightness  subsystem  uevent
bl_power           device      power           type
root@stm32mp1:/sys/devices/platform/soc/5a000000.dsi/backlight/5a000000.dsi.0# echo 240 > brightness
```

### DRM

#### modetest

```shell
root@stm32mp1:~# modetest -h
usage: modetest [-acDdefMPpsCvw]

 Query options:

        -c      list connectors
        -e      list encoders
        -f      list framebuffers
        -p      list CRTCs and planes (pipes)

 Test options:

        -P <plane_id>@<crtc_id>:<w>x<h>[+<x>+<y>][*<scale>][@<format>]  set a plane
        -s <connector_id>[,<connector_id>][@<crtc_id>]:<mode>[-<vrefresh>][@<format>]   set a mode
        -C      test hw cursor
        -v      test vsynced page flipping
        -w <obj_id>:<prop_name>:<value> set property
        -a      use atomic API

 Generic options:

        -d      drop master after mode set
        -M module       use the given driver
        -D device       use the given device

        Default is to dump all info.

```

##### connector

```shell
root@stm32mp1:~# modetest -M stm -c
Connectors:
id      encoder status          name            size (mm)       modes   encoders
29      0       disconnected    HDMI-A-1        0x0             0       28
  props:
        1 EDID:
                flags: immutable blob
                blobs:

                value:
        2 DPMS:
                flags: enum
                enums: On=0 Standby=1 Suspend=2 Off=3
                value: 0
        5 link-status:
                flags: enum
                enums: Good=0 Bad=1
                value: 0
        6 non-desktop:
                flags: immutable range
                values: 0 1
                value: 0
        19 CRTC_ID:
                flags: object
                value: 0
31      30      connected       DSI-1           52x86           1       30
  modes:
        name refresh (Hz) hdisp hss hse htot vdisp vss vse vtot)
  480x800 50 480 578 610 708 800 815 825 839 29700 flags: ; type: preferred, driver
  props:
        1 EDID:
                flags: immutable blob
                blobs:

                value:
        2 DPMS:
                flags: enum
                enums: On=0 Standby=1 Suspend=2 Off=3
                value: 0
        5 link-status:
                flags: enum
                enums: Good=0 Bad=1
                value: 0
        6 non-desktop:
                flags: immutable range
                values: 0 1
                value: 0
```

##### encoder

```shell
root@stm32mp1:~# modetest -M stm -e
Encoders:
id      crtc    type    possible crtcs  possible clones
28      0       DPI     0x00000001      0x00000000
30      34      DSI     0x00000001      0x00000000
```

##### CRTCs and Planes

```shell
root@stm32mp1:~# modetest -M stm -p
CRTCs:
id      fb      pos     size
34      40      (0,0)   (480x800)
  480x800 50 480 578 610 708 800 815 825 839 29700 flags: ; type: preferred, driver
  props:
        20 ACTIVE:
                flags: range
                values: 0 1
                value: 1
        21 MODE_ID:
                flags: blob
                blobs:

                value:
                        04740000e00142026202c40200002003
                        2f033903470300003200000000000000
                        48000000343830783830300000000000
                        00000000000000000000000000000000
                        00000000
        18 OUT_FENCE_PTR:
                flags: range
                values: 0 18446744073709551615
                value: 0
        25 GAMMA_LUT:
                flags: blob
                blobs:

                value:
        26 GAMMA_LUT_SIZE:
                flags: immutable range
                values: 0 4294967295
                value: 256

Planes:
id      crtc    fb      CRTC x,y        x,y     gamma size      possible crtcs
32      34      40      0,0             0,0     0               0x00000001
  formats: AR24 XR24 RG24 RG16 AR15 XR15 AR12 XR12 C8
  props:
        7 type:
                flags: immutable enum
                enums: Overlay=0 Primary=1 Cursor=2
                value: 1
        16 FB_ID:
                flags: object
                value: 40
        17 IN_FENCE_FD:
                flags: signed range
                values: -1 2147483647
                value: -1
        19 CRTC_ID:
                flags: object
                value: 34
        12 CRTC_X:
                flags: signed range
                values: -2147483648 2147483647
                value: 0
        13 CRTC_Y:
                flags: signed range
                values: -2147483648 2147483647
                value: 0
        14 CRTC_W:
                flags: range
                values: 0 2147483647
                value: 480
        15 CRTC_H:
                flags: range
                values: 0 2147483647
                value: 800
        8 SRC_X:
                flags: range
                values: 0 4294967295
                value: 0
        9 SRC_Y:
                flags: range
                values: 0 4294967295
                value: 0
        10 SRC_W:
                flags: range
                values: 0 4294967295
                value: 31457280
        11 SRC_H:
                flags: range
                values: 0 4294967295
                value: 52428800
        27 IN_FORMATS:
                flags: immutable blob
                blobs:

                value:
                        01000000000000000900000018000000
                        01000000400000004152323458523234
                        52473234524731364152313558523135
                        41523132585231324338202000000000
                        ff010000000000000000000000000000
                        0000000000000000
                in_formats blob decoded:
                         AR24:  LINEAR
                         XR24:  LINEAR
                         RG24:  LINEAR
                         RG16:  LINEAR
                         AR15:  LINEAR
                         XR15:  LINEAR
                         AR12:  LINEAR
                         XR12:  LINEAR
                         C8  :  LINEAR
35      0       0       0,0             0,0     0               0x00000001
  formats: AR24 RG24 RG16 AR15 AR12 C8
  props:
        7 type:
                flags: immutable enum
                enums: Overlay=0 Primary=1 Cursor=2
                value: 0
        16 FB_ID:
                flags: object
                value: 0
        17 IN_FENCE_FD:
                flags: signed range
                values: -1 2147483647
                value: -1
        19 CRTC_ID:
                flags: object
                value: 0
        12 CRTC_X:
                flags: signed range
                values: -2147483648 2147483647
                value: 0
        13 CRTC_Y:
                flags: signed range
                values: -2147483648 2147483647
                value: 0
        14 CRTC_W:
                flags: range
                values: 0 2147483647
                value: 0
        15 CRTC_H:
                flags: range
                values: 0 2147483647
                value: 0
        8 SRC_X:
                flags: range
                values: 0 4294967295
                value: 0
        9 SRC_Y:
                flags: range
                values: 0 4294967295
                value: 0
        10 SRC_W:
                flags: range
                values: 0 4294967295
                value: 0
        11 SRC_H:
                flags: range
                values: 0 4294967295
                value: 0
        27 IN_FORMATS:
                flags: immutable blob
                blobs:

                value:
                        01000000000000000600000018000000
                        01000000300000004152323452473234
                        52473136415231354152313243382020
                        3f000000000000000000000000000000
                        0000000000000000
                in_formats blob decoded:
                         AR24:  LINEAR
                         RG24:  LINEAR
                         RG16:  LINEAR
                         AR15:  LINEAR
                         AR12:  LINEAR
                         C8  :  LINEAR
```

