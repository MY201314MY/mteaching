import time
from periphery import GPIO
"""
RES third 11
DC second 12
"""

RST = GPIO("/dev/gpiochip0", 11, "out")
DC  = GPIO("/dev/gpiochip0", 12, "out")


for _ in range(6):
    print(".")
    DC.write(False)
    time.sleep(1)
    DC.write(True)
    time.sleep(1)

RST.close()