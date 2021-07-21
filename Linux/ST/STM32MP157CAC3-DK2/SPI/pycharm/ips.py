import time
from periphery import SPI
from periphery import GPIO
"""
RES third 11
DC second 12
"""
RST = GPIO("/dev/gpiochip0", 11, "out")
DC  = GPIO("/dev/gpiochip0", 12, "out")
spi = SPI("/dev/spidev0.0", 2, 1000000)

def LCD_DC(choose):
    if choose == 1:
        DC.write(True)
    else:
        DC.write(False)

def LCD_RST(choose):
    if choose == 1:
        RST.write(True)
    else:
        RST.write(False)

buffer = [0]

def LCD_Write_Cmd(cmd):
    LCD_DC(0)
    buffer[0] = cmd
    spi.transfer(buffer)

def LCD_Write_Data(dat):
    LCD_DC(1)
    buffer[0] = dat
    spi.transfer(buffer)

def LCD_Address_Set(x0, y0, x1, y1):
    LCD_Write_Cmd(0x2a)
    LCD_Write_Data(x0>>8)
    LCD_Write_Data(x0&0xFF)
    LCD_Write_Data(x1>>8)
    LCD_Write_Data(x1&0xFF)

    LCD_Write_Cmd(0x2b)
    LCD_Write_Data(y0>>8)
    LCD_Write_Data(y0&0xFF)
    LCD_Write_Data(y1>>8)
    LCD_Write_Data(y1&0XFF)

    LCD_Write_Cmd(0x2C)

def LCD_Full_Display():
    color = []

    for i in range(0, 240*2):
        if i%2==0:
            color.append(0x00)
        else:
            color.append(0xFF)
    print("the len of buffer: {0}".format(len(color)))
    LCD_Address_Set(0, 0, 239, 239)
    LCD_DC(1)
    for _ in range(0, 240*2):
        spi.transfer(color)

def LCD_Init():
    LCD_RST(0)
    time.sleep(0.100)
    LCD_RST(1)
	
    time.sleep(0.120)
    
    LCD_Write_Cmd(0x11)
    time.sleep(0.120)

    
    LCD_Write_Cmd(0x36)
    LCD_Write_Data(0x00)
    
    LCD_Write_Cmd(0x3A)
    LCD_Write_Data(0x65)
    
    LCD_Write_Cmd(0xB2)
    LCD_Write_Data(0x0C)
    LCD_Write_Data(0x0C)
    LCD_Write_Data(0x00)
    LCD_Write_Data(0x33)
    LCD_Write_Data(0x33)
    
    LCD_Write_Cmd(0xB7)
    LCD_Write_Data(0x72)
    
    LCD_Write_Cmd(0xBB)
    LCD_Write_Data(0x3D)
    
    LCD_Write_Cmd(0xC0)
    LCD_Write_Data(0x2C)
    
    LCD_Write_Cmd(0xC2)
    LCD_Write_Data(0x01)
    
    LCD_Write_Cmd(0xC3)
    LCD_Write_Data(0x19)
    
    LCD_Write_Cmd(0xC4)
    LCD_Write_Data(0x20)
    
    LCD_Write_Cmd(0xC6)
    LCD_Write_Data(0x0F)
    
    LCD_Write_Cmd(0xD0)
    LCD_Write_Data(0xA4)
    LCD_Write_Data(0xA1)

    LCD_Write_Cmd(0xE0)
    LCD_Write_Data(0xD0)
    LCD_Write_Data(0x04)
    LCD_Write_Data(0x0D)
    LCD_Write_Data(0x11)
    LCD_Write_Data(0x13)
    LCD_Write_Data(0x2B)
    LCD_Write_Data(0x3F)
    LCD_Write_Data(0x54)
    LCD_Write_Data(0x4C)
    LCD_Write_Data(0x18)
    LCD_Write_Data(0x0D)
    LCD_Write_Data(0x0B)
    LCD_Write_Data(0x1F)
    LCD_Write_Data(0x23)
    
    LCD_Write_Cmd(0xE1)
    LCD_Write_Data(0xD0)
    LCD_Write_Data(0x04)
    LCD_Write_Data(0x0C)
    LCD_Write_Data(0x11)
    LCD_Write_Data(0x13)
    LCD_Write_Data(0x2C)
    LCD_Write_Data(0x3F)
    LCD_Write_Data(0x44)
    LCD_Write_Data(0x51)
    LCD_Write_Data(0x2F)
    LCD_Write_Data(0x1F)
    LCD_Write_Data(0x1F)
    LCD_Write_Data(0x20)
    LCD_Write_Data(0x23)
    
    LCD_Write_Cmd(0x21)
    LCD_Write_Cmd(0x29)
    
LCD_Init()
LCD_Full_Display()

RST.close()
DC.close()
spi.close()