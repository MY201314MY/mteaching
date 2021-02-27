obj := sql

default:
	$(CC) $(obj).c -o $(obj) -lsqlite3
	scp $(obj) root@192.168.7.1:/home/root/

clean:
	rm -f $(obj)