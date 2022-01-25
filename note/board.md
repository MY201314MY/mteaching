##### This is designed for STM32MP157

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
```

**ffmpeg**

```shell
ffmpeg -i norway.mp4 -s 800*480 output.mp4 -q:v1
ffmpeg -i radio.mp4 -q:v 5 -c:v mpeg1video -c:a mp2 -format mpeg maria.mpg
ffmpeg -i maria.mpg -strict -2 -s 240x428 output.mpg
```

###### **display the fps of mi-pi**

```
cat /sys/kernel/debug/dri/0/state | grep fps -m1
```

###### **connect to wireless network**

```shell
ifconfig wlan0 up
sleep 5

wpa_supplicant -B -i wlan0 -c /etc/wpa_supplicant.conf
iw wlan0 link
udhcpc -i wlan0
ping www.baidu.com -c 4
ntpdate ntp1.aliyun.com
```

###### initial wireless network

```shell
wpa_passphrase TP-LINK_81B5 w.15619288881w >> /etc/wpa_supplicant.conf
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

###### ntp

```shell
apt-get install tzdata-asia
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

weston

```shell
#start
systemctl start weston
#stop
systemctl stop weston
```

fbtft

```shell
fb-test -r
sleep 1
fb-test -g
sleep 1
fb-test -b
sleep 1
fb-test -w
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

##### Build Kernel in NEW

###### error

```
[   11.488579] galcore: disagrees about version of symbol module_layout
[   11.519854] brcmutil: disagrees about version of symbol module_layout
[   11.525627] brcmutil: disagrees about version of symbol module_layout
[   11.572800] typec: disagrees about version of symbol module_layout
[  OK  ] Listening on dropbear.socket.
[  OK  ] Reached target Sockets.
[  OK  ] Reached target Basic System.
[  OK  ] Started Kernel Logging Service.
[  OK  ] Started System Logging Service.
[  OK  ] Started D-Bus System Message Bus.
[   11.984871] soundcore: disagrees about version of symbol module_layout
```

###### normal

```
[   11.601229] galcore: loading out-of-tree module taints kernel.
[   11.631800] Bluetooth: HCI UART protocol Broadcom registered
[  OK  ] Listening on dropbear.socket.
[  OK  ] Reached target Sockets.
[  OK  ] Reached target Basic System.
[   11.750629] Galcore version 6.4.3.279124
[  OK  ] Started Kernel Logging Service.
[  OK  ] Started System Logging Service.
[  OK  ] Started D-Bus System Message Bus.
[   12.037074] cfg80211: Loading compiled-in X.509 certificates for regulatory database
[   12.074804] Bluetooth: hci0: BCM: chip id 94
[   12.078493] Bluetooth: hci0: BCM: features 0x2e
[   12.083789] Bluetooth: hci0: BCM43430A1
[   12.086265] Bluetooth: hci0: BCM43430A1 (001.002.009) build 0000
[   12.100257] Bluetooth: hci0: BCM43430A1 'brcm/BCM43430A1.hcd' Patch
[   12.248575] cfg80211: Loaded X.509 cert 'sforshee: 00b28ddf47aef9cea7'
[  OK  ] Started GENIVI DLT logging daemon.
```



