obj := transmit

target:
	$(CC) $(obj).c -o $(obj)
	scp $(obj) root@192.168.7.1:/home/root/execute/

clean:
	rm -f $(obj)