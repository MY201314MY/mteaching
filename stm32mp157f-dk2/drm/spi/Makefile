# Makefile for external out-of-tree Linux kernel module

# Object file(s) to be built
obj-m := panel-sitronix-st7796.o

# Path to the directory that contains the Linux kernel source code
# and the configuration file (.config)
KERNEL_DIR ?= /home/pi/STMicroelectronics/linux-stm32mp

# Path to the directory that contains the source file(s) to compile
PWD := $(shell pwd) 
  
default:
	$(MAKE) -C $(KERNEL_DIR) M=$(PWD) modules

clean:  
	$(MAKE) -C $(KERNEL_DIR) M=$(PWD) clean