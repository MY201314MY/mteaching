KERNELDIR := /home/pi/stm32mp157/stm32mp1-openstlinux-5-4-dunfell-mp1-20-11-12/sources/arm-ostl-linux-gnueabi/linux-stm32mp-5.4.56-r0/linux-5.4.56

CURRENT_PATH := $(shell pwd)

obj-m := maria.o

target:
	$(MAKE) -C $(KERNELDIR) M=$(CURRENT_PATH) modules
	scp maria.ko root@192.168.7.1:/home/root
	
clean:
	$(MAKE) -C $(KERNELDIR) M=$(CURRENT_PATH) clean