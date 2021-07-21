#include <stdint.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>
#include <fcntl.h>
#include <time.h>
#include <sys/ioctl.h>
#include <linux/ioctl.h>
#include <sys/stat.h>
#include <linux/types.h>
#include <linux/spi/spidev.h>

#define ARRAY_SIZE 1152
uint8_t default_tx[ARRAY_SIZE];
uint8_t default_rx[ARRAY_SIZE];

int SPI_Init();
void transfer(uint8_t const *tx, uint8_t const *rx, size_t len);
void SPI_Exit();