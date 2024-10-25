./../../../opt/arm-gnu-toolchain-11.3.rel1-x86_64-arm-none-linux-gnueabihf/bin/arm-none-linux-gnueabihf-gcc main.c 
scp a.out root@192.168.7.1:/home/root/
a.out

gst-launch-1.0 -v filesrc location=/home/root/AirPods.mp4 ! qtdemux name=demux \
demux.audio_0 ! queue ! decodebin ! audioconvert ! audioresample ! autoaudiosink \
demux.video_0 ! queue ! decodebin ! videoconvert ! autovideosink

gst-launch-1.0 filesrc location=/home/weston/Videos/S6.mp4 ! qtdemux name=demux \
demux.audio_0 ! queue ! decodebin ! audioconvert ! audioresample ! autoaudiosink \
demux.video_0 ! queue ! decodebin ! videoconvert ! autovideosink

                                                                                                                                                     100%   12KB 229.4KB/s   00:00    