```shell
echo Hello > backup.txt
file backup.txt 
backup.txt: ASCII text
ls -l backup.txt 
-rw-rw-r-- 1 pi pi 6  6月  9 09:13 backup.txt
hexdump backup.txt -C
00000000  48 65 6c 6c 6f 0a                                 |Hello.|
00000006

echo 你好 > backup.txt
file backup.txt 
backup.txt: Unicode text, UTF-8 text
ls -l backup.txt
-rw-rw-r-- 1 pi pi 7  6月  9 09:45 backup.txt
pi@mac:~/Audio$ hexdump backup.txt -C
00000000  e4 bd a0 e5 a5 bd 0a                              |.......|
00000007
```

[Reference URL](https://blog.csdn.net/hanyupeng123/article/details/109357407)