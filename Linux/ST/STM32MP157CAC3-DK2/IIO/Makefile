obj := maria

default:
	$(CC) $(obj).c -o $(obj) -liio
	scp $(obj) root@192.168.7.1:/home/root

clean:
	rm -f $(obj)