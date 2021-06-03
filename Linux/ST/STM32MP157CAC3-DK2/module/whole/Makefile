KERNELDIR := /home/pi/important/linux-stm32mp-5.4.31-r0/linux-5.4.31

CURRENT_PATH := $(shell pwd)

obj-m := maria.o

target:
	$(MAKE) -C $(KERNELDIR) M=$(CURRENT_PATH) modules
	
clean:
	$(MAKE) -C $(KERNELDIR) M=$(CURRENT_PATH) clean