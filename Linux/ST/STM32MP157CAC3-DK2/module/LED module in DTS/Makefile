# Makefile for external out-of-tree Linux kernel module

# Object file(s) to be built
obj-m := module.o

# Path to the directory that contains the Linux kernel source code
# and the configuration file (.config)
KERNEL_DIR ?= /home/pi/stm32mp157/stm32mp1-openstlinux-5-4-dunfell-mp1-20-11-12/sources/arm-ostl-linux-gnueabi/linux-stm32mp-5.4.56-r0/linux-5.4.56

# Path to the directory that contains the generated objects
DESTDIR ?= $(KERNEL_DIR)/install_artifact

# Path to the directory that contains the source file(s) to compile
PWD := $(shell pwd) 
  
default:
	$(MAKE) -C $(KERNEL_DIR) M=$(PWD) modules

install:
	$(MAKE) -C $(KERNEL_DIR) M=$(PWD) INSTALL_MOD_PATH=$(DESTDIR) modules_install

clean:  
	$(MAKE) -C $(KERNEL_DIR) M=$(PWD) clean