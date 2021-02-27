obj := semaphore

all:
	$(CC) $(obj).c -o $(obj) -lpthread
	scp $(obj) root@192.168.7.1:/home/root

clean:
	rm -f $(obj)