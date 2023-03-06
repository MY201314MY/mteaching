```shell
gst-launch-1.0 filesrc location=/home/root/car.mp4 ! decodebin ! videoconvert ! videoscale ! video/x-raw,width=800,height=480 ! autovideosink
```



```shell
gst-launch-1.0 filesrc location=/home/root/t.mp4 ! decodebin ! videoconvert ! autovideosink
```



```shell
gst-launch-1.0 filesrc location=/home/root/watch.mp4 ! qtdemux name=demux \
demux.audio_0 ! queue ! decodebin ! audioconvert ! audioresample ! autoaudiosink \
demux.video_0 ! queue ! decodebin ! videoconvert ! videoscale ! video/x-raw,width=400,height=240 ! autovideosink &
```



```shell
gst-launch-1.0 filesrc location=/home/root/watch.mp4 ! qtdemux name=demux \
demux.audio_0 ! queue ! decodebin ! audioconvert ! audioresample ! autoaudiosink \
demux.video_0 ! queue ! decodebin ! videoconvert ! videoparse width=1920 height=816 format=i420 ! fakesink
```



```
gst-launch-1.0 filesrc location=/home/root/watch.mp4 ! qtdemux name=demux \
demux.audio_0 ! queue ! aacparse ! avdec_aac ! audioconvert ! audioresample ! autoaudiosink \
demux.video_0 ! queue ! h264parse  ! avdec_h264 ! videoconvert ! videoparse width=80 height=40 format=i420 ! fakesink
```





```shell
gst-inspect-1.0 --plugin | grep avdec_aac
```



```
gst-launch-1.0 filesrc location=/home/root/li.mp4 ! decodebin ! videoconvert ! autovideosink
```



```
ffmpeg -i fast.mp4 -strict -2 -vf scale=800:480 output.mp4  
```



```shell
gst-launch-1.0 filesrc location=/home/root/li.mp4 ! qtdemux name=demux \
demux.audio_0 ! queue ! decodebin ! audioconvert ! audioresample ! autoaudiosink \
demux.video_0 ! queue ! decodebin ! videoconvert ! autovideosink fullscreen=TRUE &
```



```
gst-launch-1.0 filesrc location=/home/root/watch.mp4 ! qtdemux name=demux \
demux.audio_0 ! queue ! decodebin ! audioconvert ! audioresample ! autoaudiosink \
demux.video_0 ! queue ! decodebin ! videoconvert ! fakesink
```

[videoscale](https://github.com/Jan-Eisenhauer/lightcube-camera/blob/c1f2e9db1ab3a702da54e12b30ead13a41ba097f/src/camera.c)

[qtdemux](https://github.com/garung



```shell
cat /sys/kernel/debug/dri/0/state | grep fps -m1 | grep -o '[0-9]\+'
```



***VOLTAGE:10.28V***