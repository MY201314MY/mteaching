obj := main

default:
	#source ~/STM32MPU_workspace/STM32MP15-Ecosystem-v3.0.0/Developer-Package/SDK/environment-setup-cortexa7t2hf-neon-vfpv4-ostl-linux-gnueabi 
	$(CC) $(obj).c -o $(obj) 

transfer:
	scp $(obj) root@192.168.7.1:/home/root

clean:
	rm -f $(obj)