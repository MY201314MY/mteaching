```shell
ffmpeg -version
```



```shell
ffmpeg -i test.avi test.mp4
```



```shell
ffmpeg -i test.avi -c:v libx264 test.mp4
```

Convert

```shell
ffmpeg -i test.avi -c:v libx264 -preset ultrafast test.mp4
    ultrafast
    superfast
    veryfast
    faster
    fast
    medium(default)
    slow
    slower
    veryslow
```



```shell
0-51 值越大图像质量越差
ffmpeg -i test.avi -c:v libx264 -crf 22 test.mp4
```



```
ffmpeg -i sound.wav sound.mp3
```

