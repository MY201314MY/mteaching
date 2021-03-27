CC = arm-linux-gcc
LD = arm-linux-ld
OBJCOPY = arm-linux-objcopy

obj = start.o sys.o irq.o led.o button.o uart.o timer.o sdram.o nand.o init.o lcddrv.o framebuffer.o font.o rtc.o main.o

CFLAGS := -fno-builtin

output.bin:$(obj)
	$(LD) -Tmteaching.lds $^ -o output.elf
	$(OBJCOPY) -O binary -S output.elf $@

%.o:%.S
	$(CC) $(CFLAGS) -c $< -o $@ 

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

flash:
	maria 0 1 0 0 0 output.bin

clean:
	rm *.bin *.o *.elf
