#### Can in Linux

```shell
ip addr
ip link set can0 type can bitrate 500000
ip link set can0 up type can bitrate 1000000 dbitrate 2000000 fd on
ip -details link show can0
ip link set can0 up
ip -details link show can0
ifconfig
```

