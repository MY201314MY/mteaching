import os

if __name__ == '__main__':
    file = open("LED_Blinker.bin", 'rb')
    size = os.path.getsize("LED_Blinker.bin")
    print(size)
    for i in range(size):
        data = file.read(1)
        print("0x%02X, " % data[0], end="")
        if (i+1) % 16 == 0:
            print()