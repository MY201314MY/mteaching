import struct

if __name__ == '__main__':
    print("Get FrameBuff")

    with open(file="image.bin", mode="rb") as f:
        array = f.read(390*209*4)

    with open(file="image.bin", mode="rb") as f:
        b = f.read(1)

    print(type(array[0]))
    print(type(b))
    print(array[0])
    num = struct.unpack('B', b)
    print(type(num))