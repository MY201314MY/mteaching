KERNELDIR := /home/pi/important/linux-stm32mp-5.4.31-r0/linux-5.4.31

CURRENT_PATH := $(shell pwd)

obj-m := maria.o

target:
	make -C $(KERNELDIR) M=$(CURRENT_PATH) modules
	
clean:
	$(CC) -C $(KERNELDIR) M=$(CURRENT_PATH) clean