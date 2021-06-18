import dbus

#reference URL:https://blog.csdn.net/zhuo_lee_new/article/details/106626680
bus = dbus.SystemBus()

interface = dbus.Interface(object=bus.get_object(bus_name="org.bluez", object_path="/org/bluez/hci0/dev_30_AE_A4_12_CB_56/service0028/char0029"),
                            dbus_interface="org.bluez.GattCharacteristic1")

result = interface.ReadValue([])
print("Read Value:{0}",format(result))

choice = input("Please input on/off to control the LED:")

if choice == "on":
    print("Turn ON the LED.")
else:
    print("Turn ON the LED.")

interface.WriteValue(choice.encode(), [])