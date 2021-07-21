obj := main

default:
	$(CC) $(obj).c SPI.c -o $(obj) 

transfer:
	scp $(obj) root@192.168.7.1:/home/root

clean:
	rm -f $(obj)