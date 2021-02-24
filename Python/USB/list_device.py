import usb

if __name__ == '__main__':
    print("USB COMMUNICATION VERSION: %s" % usb.__version__)

    all = usb.core.find(find_all=True)
    if all is None:
        print("Nothing device found. . .")

    print(all)
    for item in all:
        print(item)