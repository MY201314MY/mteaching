from periphery import I2C
i2c = I2C("/dev/i2c-0")

calibrate = [I2C.Message([0x00, 0x01, 0x9f]), I2C.Message([0x05, 0x20, 0x00])]

i2c.transfer(0x40, calibrate)

voltage = [I2C.Message([0x02]), I2C.Message([0x00, 0x00], read=True)]
current = [I2C.Message([0x04]), I2C.Message([0x00, 0x00], read=True)]
power   = [I2C.Message([0x03]), I2C.Message([0x00, 0x00], read=True)]

i2c.transfer(0x40, voltage)
i2c.transfer(0x40, current)
i2c.transfer(0x40, power)


print("Voltage = {0} V".format(round(((voltage[1].data[0]<<8 | voltage[1].data[1])>>3)*4)*0.001, 2))
print("Current = {0} mA".format(round(current[1].data[0]<<8 | current[1].data[1])/20, 2))
print("Power = {0} mW".format(power[1].data[0]<<8 | power[1].data[1]))
