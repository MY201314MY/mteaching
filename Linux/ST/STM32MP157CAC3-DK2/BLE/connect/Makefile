obj := way

default:
	$(CC) $(obj).c -o $(obj) -lbluetooth
	scp $(obj) root@192.168.7.1:/home/root

clean:
	rm -f $(obj)