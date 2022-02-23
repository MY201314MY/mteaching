#### SSH

##### NO PASSWORD

[Reference url]: https://www.cnblogs.com/pzzrudlf/articles/12287162.html

```shell
#for VS Code
cd ~/.ssh
ssh-keygen
ssh-copy-id ubuntu@82.157.101.63
#for putty addition
#.ssh/config
Host 82.157.101.63
  HostName 82.157.101.63
  User ubuntu
```
