##### This is designed for STM32MP157F-DK2

Support for ST7701

```dtd
panel_otm8009a: panel-otm8009a@0 {
    compatible = "techstar,ts8550b";
    reg = <0>;
    reset-gpios = <&gpioe 4 GPIO_ACTIVE_LOW>;
    VCC-supply = <&v3v3>;
    IOVCC-supply = <&v3v3>;
    status = "okay";

    port {
    	panel_in: endpoint {
    		remote-endpoint = <&dsi_out>;
    	};
    };
};
```



###### **FPS**

```shell
(while true; do export fps=`cat /sys/kernel/debug/dri/0/state | grep fps -m1 | grep -o '[0-9]\+'`; echo display ${fps}fps; sleep 4; done) &
```

###### curl

```shell
curl http://121.5.149.236/snow.mpg --verbose --output snow.mpg
```

##### gstreamer

###### Internet file

Run After Exit SSH

```shell
nohup gst-launch-1.0 playbin uri=http://82.157.101.63/watch.mp4 &
```

###### **local file**

```shell
gst-launch-1.0 playbin uri=file:///home/root/watch.mp4
/* Display in framebuffer */
gst-launch-1.0 filesrc location=/home/root/littleVGL/maria.mpg ! decodebin ! videoconvert ! fbdevsink device=/dev/fb0
```

**ffmpeg**

```shell
ffmpeg -i norway.mp4 -s 800*480 output.mp4 -q:v 1
ffmpeg -i radio.mp4 -q:v 5 -c:v mpeg1video -c:a mp2 -format mpeg maria.mpg
ffmpeg -i maria.mpg -strict -2 -s 240x428 output.mpg

ffmpeg -i in.mp4 -vcodec libx264 -preset veryslow -threads 2 -s 800*480 -acodec copy out.mp4
```

###### information

```shell
gst-discoverer-1.0 sight.mp4
 
Analyzing file:///home/root/Video/sight.mp4
Done discovering file:///home/root/Video/sight.mp4

Topology:
  container: Quicktime
    audio: MPEG-4 AAC
    video: H.264 (High Profile)

Properties:
  Duration: 0:00:09.267000000
  Seekable: yes
  Live: no
  Tags:
      audio codec: MPEG-4 AAC audio
      maximum bitrate: 69000
      bitrate: 55392
      encoder: Lavf58.29.100
      container format: ISO MP4/M4A
      video codec: H.264 / AVC
```

**gst-inspect-1.0**

```shell
gst-inspect-1.0 fbdevsink
Factory Details:
  Rank                     none (0)
  Long-name                fbdev video sink
  Klass                    Sink/Video
  Description              Linux framebuffer videosink
  Author                   Sean D'Epagnier <sean@depagnier.com>

Plugin Details:
  Name                     fbdevsink
  Description              Linux framebuffer video sink
  Filename                 /usr/lib/gstreamer-1.0/libgstfbdevsink.so
  Version                  1.14.4
  License                  LGPL
  Source module            gst-plugins-bad
  Source release date      2018-10-02
  Binary package           GStreamer Bad Plug-ins source release
  Origin URL               Unknown package origin

GObject
 +----GInitiallyUnowned
       +----GstObject
             +----GstElement
                   +----GstBaseSink
                         +----GstVideoSink
                               +----GstFBDEVSink

Pad Templates:
  SINK template: 'sink'
    Availability: Always
    Capabilities:
      video/x-raw
                 format: { (string)RGB, (string)BGR, (string)BGRx, (string)xBGR, (string)RGB, (string)RGBx, (string)xRGB, (string)RGB15, (string)RGB16 }
                  width: [ 1, 2147483647 ]
                 height: [ 1, 2147483647 ]
              framerate: [ 0/1, 2147483647/1 ]

Element has no clocking capabilities.
Element has no URI handling capabilities.

Pads:
  SINK: 'sink'
    Pad Template: 'sink'

Element Properties:
  name                : The name of the object
                        flags: readable, writable
                        String. Default: "fbdevsink0"
  parent              : The parent of the object
                        flags: readable, writable
                        Object of type "GstObject"
  sync                : Sync on the clock
                        flags: readable, writable
                        Boolean. Default: true
  max-lateness        : Maximum number of nanoseconds that a buffer can be late before it is dropped (-1 unlimited)
                        flags: readable, writable
                        Integer64. Range: -1 - 9223372036854775807 Default: 20000000
  qos                 : Generate Quality-of-Service events upstream
                        flags: readable, writable
                        Boolean. Default: true
  async               : Go asynchronously to PAUSED
                        flags: readable, writable
                        Boolean. Default: true
  ts-offset           : Timestamp offset in nanoseconds
                        flags: readable, writable
                        Integer64. Range: -9223372036854775808 - 9223372036854775807 Default: 0
  enable-last-sample  : Enable the last-sample property
                        flags: readable, writable
                        Boolean. Default: true
  last-sample         : The last sample received in the sink
                        flags: readable
                        Boxed pointer of type "GstSample"
  blocksize           : Size in bytes to pull per buffer (0 = default)
                        flags: readable, writable
                        Unsigned Integer. Range: 0 - 4294967295 Default: 4096
  render-delay        : Additional render delay of the sink in nanoseconds
                        flags: readable, writable
                        Unsigned Integer64. Range: 0 - 18446744073709551615 Default: 0
  throttle-time       : The time to keep between rendered buffers (0 = disabled)
                        flags: readable, writable
                        Unsigned Integer64. Range: 0 - 18446744073709551615 Default: 0
  max-bitrate         : The maximum bits per second to render (0 = disabled)
                        flags: readable, writable
                        Unsigned Integer64. Range: 0 - 18446744073709551615 Default: 0
  show-preroll-frame  : Whether to render video frames during preroll
                        flags: readable, writable
                        Boolean. Default: true
  device              : The framebuffer device eg: /dev/fb0
                        flags: readable, writable
                        String. Default: null
```



###### **display the fps of mi-pi**

```
cat /sys/kernel/debug/dri/0/state | grep fps -m1
```

##### iw

```shell
#scan SSID
iw dev wlan0 scan | grep SSID
#link status
iw dev wlan0 link
#list dev performance
iw dev list
#connect SSID without password
iw dev wlan0 connect mteaching
#connect SSID with password
iw dev wlan0 connect mteaching keys d:0:12345678
```

###### **connect to wireless network**

```shell
ifconfig wlan0 up
sleep 5

wpa_supplicant -B -i wlan0 -c /etc/wpa_supplicant.conf
iw dev wlan0 link
udhcpc -i wlan0
ping www.baidu.com -c 4
ntpdate ntp1.aliyun.com
```

###### initial wireless network

```shell
wpa_passphrase mteaching 12345678 >> /etc/wpa_supplicant.conf
```



```shell
#No Password
wpa_passphrase longsys >> /etc/wpa_supplicant.conf
```

###### **wpa_supplicant.conf**

```sh
root@stm32mp1:~# cat /etc/wpa_supplicant.conf
ctrl_interface=/var/run/wpa_supplicant
ctrl_interface_group=0
update_config=1

network={
        key_mgmt=NONE
}
```

##### script

###### download

```shell
echo "- - - - Viedo Download - - - -"

items=(
"arduino.mp4" "done.mp4" "ferrari.mp4" "mac.mp4" "mpu.mp4"
"norway.mp4" "sight.mp4" "signal.mp4" "travel.mp4" "watch.mp4"
)

for item in ${items[*]}
do 
	wget "http://82.157.101.63/${item}" 
	echo "[done]"
done
```

###### without certificate

```shell
wget https://www.apple.com.cn/105/media/cn/iphone-12/2020/7f5b7de7-9f8c-41eb-bf3b-f294773108e6/anim/hero-purple/large_2x.mp4 --no-check-certificate
```



###### play

```shell
ehco "- - - Video Player by GStreamer - - -"
for item in `ls *.mp4`
do
	echo "Now Play Video -->[${item}]"
	gst-launch-1.0 playbin uri=file:///home/root/Video/${item}
	echo -e "- - - End - - -\r\n"
done
```

###### scp

**transfer file between hosts**

```
scp output.mpeg  root@192.168.137.10:/home/root/Video
```

###### pscp

```shell
#'r' means directory supported, pscp is provided by SSH
pscp -r D:\Web\monkey root@120.26.185.144:/var/www/html
```

###### weston

```shell
#start
systemctl start weston
#stop
systemctl stop weston
```

New version

```shell
systemctl start weston@root.service

systemctl stop weston@root.service
```



##### fbtft

###### fb-test

```shell
fb-test -r
sleep 1
fb-test -g
sleep 1
fb-test -b
sleep 1
fb-test -w
```

##### monitor

###### cpu temperature

```shell
root@stm32mp1:/sys/devices/virtual/thermal/thermal_zone0# cat temp
62866
```

##### package

###### process

```shell
apt-get install nano
apt-get install redis
apt-get install nginx
apt-get install mosquitto mosquitto-clients
```

###### hardware supported by python

```shell
apt-get install python3-pip
apt-get install libgpiod-python
apt-get install python3-smbus	
apt-get install python3-spidev
```

###### software supported by python

```
apt-get install python3-dbus
apt-get install python3-sqlite3
apt-get install python3-gi
```

##### install package with pip

```shell
pip3 install paho-mqtt -i http://mirrors.aliyun.com/pypi/simple/ --trusted-host mirrors.aliyun.com
pip3 install requests -i http://mirrors.aliyun.com/pypi/simple/ --trusted-host mirrors.aliyun.com
pip3 install --user meson
export PATH=/home/pi/.local/bin:$PATH
```

###### update dtb

```shell
make dtbs
scp arch/arm/boot/dts/stm32mp157c-dk2.dtb root@192.168.7.1:/boot
```

##### apt

###### search

```shell
apt-cache searsh redis
```

##### update

###### install

```shell
apt-get install ntpdate
```

###### synchronization

```shell
ntpdate ntp1.aliyun.com
```

###### add timezone

```shell
apt-cache search zone
```

###### install timezone

```shell
apt-get install tzdata-asia
```

###### set timezone

```shell
timedatectl set-timezone 'Asia/Shanghai'
```

##### Glib

##### install

```shell
sudo apt-get install libglib2.0-dev
reference url:
	https://www.cnblogs.com/alexyuyu/articles/2555216.html
    https://blog.csdn.net/andylauren/category_6219334.html
```

##### C Build

```shell
pkg-config --cflags --libs glib-2.0
	-I/usr/include/glib-2.0 -I/usr/lib/x86_64-linux-gnu/glib-2.0/include -lglib-2.0
```

##### timestamp

**millisecond**

```c
#include <stdio.h>
#include <sys/time.h>

int main() {
    struct timeval start, end;
    gettimeofday( &start, NULL );
    sleep(3); 
    gettimeofday( &end, NULL );
    int timeInterval = 1000000 * ( end.tv_sec - start.tv_sec ) + end.tv_usec - start.tv_usec; 
    printf("time: %d us\n", timeInterval);
    return 0;
}
```

##### compression and decompression

```shell
#compression 
zip:
	zip -q -r GDBus-master.zip GDBus-master
tar:
	tar -cvf file.tar file
tar.gz
	tar -czf file.tar.gz file

#decompression
*.zip
	unzip master.zip
*.tar
	tar -xvf file.tar
*.tar.gz
	tar -xzvf file.tar.gz
*.tar.bz2
	tar xjvf file.tar.bz2
*.tar.Z
	tar -xZvf file.tar.Z
*rar
	unrar e file.rar
```

###### Shell

```shell
echo "We used the Linux shell script mainly for the installation."

if [ $EUID != 0 ];then
    echo "You aren't the root."
fi

array=(ABCDEF)
echo $array
echo ${#array[@]}

array=(A B C D E F)
echo $array
echo ${#array[@]}

for i in ${array[*]}
do
    echo $i
done

i=0
sum=0
while(( $i != 10 ))
do
#    let "i++"
    i=`expr $i + 1`
    echo $i
done

i=0
sum=0
while [[ $i != 10 ]]
do
    #let "i++"
    i=`expr $i + 1`
    echo $i
done

echo ******************************
```

##### modetest

```shell
root@stm32mp1:~# modetest -M stm
Encoders:
id      crtc    type    possible crtcs  possible clones
34      40      DSI     0x00000001      0x00000002

Connectors:
id      encoder status          name            size (mm)       modes   encoders
35      34      connected       DSI-1           52x86           2       34
  modes:
        index name refresh (Hz) hdisp hss hse htot vdisp vss vse vtot)
  #0 480x800 50.00 480 578 610 708 800 815 825 839 29700 flags: nhsync, nvsync; type: preferred, driver
  #1 480x800 60.00 480 550 582 654 800 815 825 841 33000 flags: nhsync, nvsync; type: driver
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
        4 TILE:
                flags: immutable blob
                blobs:

                value:
        20 CRTC_ID:
                flags: object
                value: 40

CRTCs:
id      fb      pos     size
40      0       (0,0)   (480x800)
  #0 480x800 50.00 480 578 610 708 800 815 825 839 29700 flags: nhsync, nvsync; type: preferred, driver
  props:
        22 ACTIVE:
                flags: range
                values: 0 1
                value: 1
        23 MODE_ID:
                flags: blob
                blobs:

                value:
                        04740000e00142026202c40200002003
                        2f03390347030000320000000a000000
                        48000000343830783830300000000000
                        00000000000000000000000000000000
                        00000000
        19 OUT_FENCE_PTR:
                flags: range
                values: 0 18446744073709551615
                value: 0
        24 VRR_ENABLED:
                flags: range
                values: 0 1
                value: 0
        31 BACKGROUND_COLOR:
                flags: range
                values: 0 18446744073709551615
                value: 18446462598732840960
        28 GAMMA_LUT:
                flags: blob
                blobs:

                value:
        29 GAMMA_LUT_SIZE:
                flags: immutable range
                values: 0 4294967295
                value: 256

Planes:
id      crtc    fb      CRTC x,y        x,y     gamma size      possible crtcs
36      0       0       0,0             0,0     0               0x00000001
  formats: AR24 XR24 RG24 RG16 AR15 XR15 AR12 XR12 C8
  props:
        8 type:
                flags: immutable enum
                enums: Overlay=0 Primary=1 Cursor=2
                value: 1
        17 FB_ID:
                flags: object
                value: 0
        18 IN_FENCE_FD:
                flags: signed range
                values: -1 2147483647
                value: -1
        20 CRTC_ID:
                flags: object
                value: 0
        13 CRTC_X:
                flags: signed range
                values: -2147483648 2147483647
                value: 0
        14 CRTC_Y:
                flags: signed range
                values: -2147483648 2147483647
                value: 0
        15 CRTC_W:
                flags: range
                values: 0 2147483647
                value: 480
        16 CRTC_H:
                flags: range
                values: 0 2147483647
                value: 800
        9 SRC_X:
                flags: range
                values: 0 4294967295
                value: 0
        10 SRC_Y:
                flags: range
                values: 0 4294967295
                value: 0
        11 SRC_W:
                flags: range
                values: 0 4294967295
                value: 31457280
        12 SRC_H:
                flags: range
                values: 0 4294967295
                value: 52428800
        30 IN_FORMATS:
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
        38 alpha:
                flags: range
                values: 0 65535
                value: 65535
        39 zpos:
                flags: immutable range
                values: 0 0
                value: 0
41      0       0       0,0             0,0     0               0x00000001
  formats: AR24 RG24 RG16 AR15 AR12 C8
  props:
        8 type:
                flags: immutable enum
                enums: Overlay=0 Primary=1 Cursor=2
                value: 0
        17 FB_ID:
                flags: object
                value: 0
        18 IN_FENCE_FD:
                flags: signed range
                values: -1 2147483647
                value: -1
        20 CRTC_ID:
                flags: object
                value: 0
        13 CRTC_X:
                flags: signed range
                values: -2147483648 2147483647
                value: 0
        14 CRTC_Y:
                flags: signed range
                values: -2147483648 2147483647
                value: 0
        15 CRTC_W:
                flags: range
                values: 0 2147483647
                value: 0
        16 CRTC_H:
                flags: range
                values: 0 2147483647
                value: 0
        9 SRC_X:
                flags: range
                values: 0 4294967295
                value: 0
        10 SRC_Y:
                flags: range
                values: 0 4294967295
                value: 0
        11 SRC_W:
                flags: range
                values: 0 4294967295
                value: 0
        12 SRC_H:
                flags: range
                values: 0 4294967295
                value: 0
        30 IN_FORMATS:
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
        43 alpha:
                flags: range
                values: 0 65535
                value: 65535
        44 zpos:
                flags: immutable range
                values: 1 1
                value: 1
```

###### make some test

```shell
#RGB Display
root@stm32mp1:~#  modetest -s 35@40:480x800@RG24 -M stm
setting mode 480x800-50.00Hz@RG24 on connectors 35, crtc 40
```



##### The realtionship betwoon Character ID and Blue Z

