###### bootdelay

```shell
printenv bootdelay
setenv bootdelay 10
saveenv
```

###### version

```shell
STM32MP> version
U-Boot 2020.10-stm32mp-r2 (Oct 05 2020 - 15:15:32 +0000)

arm-ostl-linux-gnueabi-gcc (GCC) 9.3.0
GNU ld (GNU Binutils) 2.34.0.20200220
```

###### mmc

**list**

```shell
STM32MP> mmc list
STM32 SD/MMC: 0 (SD)
STM32 SD/MMC: 1
```

**info**

```shell
STM32MP> mmc info
Device: STM32 SD/MMC
Manufacturer ID: 19
OEM: 4459
Name: 00000
Bus Speed: 50000000
Mode: SD High Speed (50MHz)
Rd Block Len: 512
SD version 3.0
High Capacity: Yes
Capacity: 3.7 GiB
Bus Width: 4-bit
Erase Group Size: 512 Bytes
```

**part**

***Erase Group Size: 512 Bytes***

```shell
STM32MP> mmc part

Partition Map for MMC device 0  --   Partition Type: EFI

Part    Start LBA       End LBA         Name
        Attributes
        Type GUID
        Partition GUID
  1     0x00000022      0x00000221      "fsbl1"
        attrs:  0x0000000000000000
        type:   8da63339-0007-60c0-c436-083ac8230908
        guid:   f4a524ea-994d-49ad-acda-2f0939402ebf
  2     0x00000222      0x00000421      "fsbl2"
        attrs:  0x0000000000000000
        type:   8da63339-0007-60c0-c436-083ac8230908
        guid:   6b44bfcf-b2c9-44c1-b317-165067eeefcf
  3     0x00000422      0x00002421      "fip"
        attrs:  0x0000000000000000
        type:   8da63339-0007-60c0-c436-083ac8230908
        guid:   47d351ab-bb00-46b6-9b2c-2ab663959785
  4     0x00002422      0x00022421      "boot"
        attrs:  0x0000000000000004
        type:   0fc63daf-8483-4772-8e79-3d69d8477de4
        type:   linux
        guid:   2fdb1d5f-736b-416b-bc27-fa85be28bde1
  5     0x00022422      0x0002a421      "vendorfs"
        attrs:  0x0000000000000000
        type:   0fc63daf-8483-4772-8e79-3d69d8477de4
        type:   linux
        guid:   3b8846e5-7bb1-4fbc-b37e-4e001747873e
  6     0x0002a422      0x0019e7e1      "rootfs"
        attrs:  0x0000000000000000
        type:   0fc63daf-8483-4772-8e79-3d69d8477de4
        type:   linux
        guid:   e91c4e10-16e6-4c0e-bd0e-77becf4a3582
  7     0x0019e7e2      0x00770fdc      "userfs"
        attrs:  0x0000000000000000
        type:   0fc63daf-8483-4772-8e79-3d69d8477de4
        type:   linux
        guid:   10de12f3-78c5-41b2-af89-bec7aa3fe7c7
```

###### DSI

[**reference**](https://forums.raspberrypi.com/viewtopic.php?t=279292)

```c
/* 
VCI=3.3V; IOVCC=1.8V;	
MIPI CLK Speed:349Mbps(110MHZ)	
PCLK:58.2MHz
H blank porch:160
H front porch:160	
H pulse width:24
	
V blank porch:10	
V front porch:12	
V pulse width:2 
*/

static const struct drm_display_mode default_mode = {
	.clock = 65000,
	.hdisplay = 480,
	.hsync_start = 480 + 160,
	.hsync_end = 480 + 160 + 24,
	.htotal = 480 + 160 + 24 + 160,
	.vdisplay = 1280,
	.vsync_start = 1280 + 12,
	.vsync_end = 1280 + 12 + 2,
	.vtotal = 1280 + 12 + 2 + 10,
	.vrefresh = 60,
};

/* clk = (((480 + 24 + 160 + 160) * (1280 + 2 + 10 + 12)) * 24 * 60 ) / 4 = 386.8Mhz */
```

**mine**

```c
static const struct drm_display_mode default_mode = {
	.clock = 65000,
	.hdisplay = 480,
	.hsync_start = 480 +10,
	.hsync_end = 480 + 10 + 2,
	.htotal = 480 + 10 + 2 + 50,
	.vdisplay = 800,
	.vsync_start = 800 + 10,
	.vsync_end = 800 + 10 + 2,
	.vtotal = 800 + 10 + 2 + 20,
	.vrefresh = 60,
};
/* 
clk = (((480 + 10 + 2 + 50) * (800 + 10 + 2 + 20)) * 24 * 60 ) / 4 =
=542*832*24*60/4=
*/
```

