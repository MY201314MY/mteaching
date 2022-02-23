### 分块下载

分段传输每次都要发送完整的HTTP

header包含获取哪些部分

获取第 0-10 个字节

```shell
pi@mac ~ % curl www.baidu.com -r 0-10 -v
*   Trying 220.181.38.149...
* TCP_NODELAY set
* Connected to www.baidu.com (220.181.38.149) port 80 (#0)
> GET / HTTP/1.1
> Host: www.baidu.com
> Range: bytes=0-10
> User-Agent: curl/7.64.1
> Accept: */*
> 
< HTTP/1.1 206 Partial Content
< Server: bfe/1.0.8.18
< Date: Sun, 30 Jan 2022 18:10:06 GMT
< Content-Type: text/html
< Content-Length: 11
< Connection: keep-alive
< Content-Range: bytes 0-10/2381
< Etag: "588604c8-94d"
< Last-Modified: Mon, 23 Jan 2017 13:27:36 GMT
< Pragma: no-cache
< Set-Cookie: BDORZ=27315; max-age=86400; domain=.baidu.com; path=/
< 
* Connection #0 to host www.baidu.com left intact
<!DOCTYPE h* Closing connection 0
```

获取第 0-100 个字节

```shell
pi@mac ~ % curl www.baidu.com -r 0-100 -v
*   Trying 220.181.38.149...
* TCP_NODELAY set
* Connected to www.baidu.com (220.181.38.149) port 80 (#0)
> GET / HTTP/1.1
> Host: www.baidu.com
> Range: bytes=0-100
> User-Agent: curl/7.64.1
> Accept: */*
> 
< HTTP/1.1 206 Partial Content
< Server: bfe/1.0.8.18
< Date: Sun, 30 Jan 2022 18:10:21 GMT
< Content-Type: text/html
< Content-Length: 101
< Connection: keep-alive
< Content-Range: bytes 0-100/2381
< Etag: "588604c8-94d"
< Last-Modified: Mon, 23 Jan 2017 13:27:36 GMT
< Pragma: no-cache
< Set-Cookie: BDORZ=27315; max-age=86400; domain=.baidu.com; path=/
< 
<!DOCTYPE html>
* Connection #0 to host www.baidu.com left intact
<!--STATUS OK--><html> <head><meta http-equiv=content-type content=text/html;charset* Closing connection 0
pi@mac ~ % 
```

