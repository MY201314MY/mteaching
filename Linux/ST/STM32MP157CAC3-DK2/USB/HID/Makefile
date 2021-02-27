usb:
	rm -f usb
	$(CC) usb.c -o usb -lusb-1.0
	scp usb root@192.168.7.1:/home/root/

clean:
	rm -f usb