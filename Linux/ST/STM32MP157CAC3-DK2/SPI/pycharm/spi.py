from periphery import SPI
spi = SPI("/dev/spidev0.0", 2, 80*1000000)

buffer = [0x2E]
spi.transfer(buffer)

spi.close()