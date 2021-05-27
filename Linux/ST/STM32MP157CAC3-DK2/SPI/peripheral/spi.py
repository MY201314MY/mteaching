#analyze
from periphery import SPI

spi = SPI("/dev/spidev0.0", 1, 500*1000)

buff = [0x03, 0x0E, 0xFF]

txt = input("address in hex(default 0x0E):")
if txt != "":
    buff[1] = int(txt, 16)

result = spi.transfer(buff)
print("register address:0x%02X -- value:0x%02X" % (buff[1], result[2]))

spi.close()

#device tree SPI without CS
from periphery import SPI
from periphery import GPIO

CS  = GPIO("/dev/gpiochip0", 12, "out")
spi = SPI("/dev/spidev0.0", 1, 1000000)

tx = [0x02, 0x0F, 0x80]
rx = [0x03, 0x0E]

CS.write(False)
spi.transfer(tx)
CS.write(True)
CS.write(False)

spi.transfer(rx)

temp = [0xFF]
result = spi.transfer(temp)
CS.write(True)
print("the read register is: 0x%02X" % result[0])

spi.close()
CS.close()

#total
from periphery import SPI
from periphery import GPIO

CS  = GPIO("/dev/gpiochip0", 12, "out")
spi = SPI("/dev/spidev0.0", 1, 80*1000000)

buff = [0x03, 0x0E, 0xFF]

txt = input("address in hex(default 0x0E):")
if txt != "":
    buff[1] = int(txt, 16)

CS.write(False)
result = spi.transfer(buff)
CS.write(True)
print("register address:0x%02X -- value:0x%02X" % (buff[1], result[2]))

spi.close()
CS.close()


from periphery import SPI
from periphery import GPIO

CS  = GPIO("/dev/gpiochip0", 12, "out")
spi = SPI("/dev/spidev0.0", 1, 80*1000000)

buff = [0x03, 0x0E, 0xFF]

txt = input("address in hex(default 0x0E):")
if txt != "":
    buff[1] = int(txt, 16)

CS.write(False)
result = spi.transfer(buff)
CS.write(True)
print("register address:0x%02X -- value:0x%02X" % (buff[1], result[2]))

spi.close()
CS.close()