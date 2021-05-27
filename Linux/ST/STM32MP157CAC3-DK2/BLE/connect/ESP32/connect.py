import dbus

bus = dbus.SystemBus()

interface = dbus.Interface(object=bus.get_object(bus_name="org.bluez", object_path="/org/bluez/hci0/dev_30_AE_A4_12_CB_56"),
                            dbus_interface="org.freedesktop.DBus.Properties")

result = interface.GetAll("org.bluez.Device1")
print(result)

interface = dbus.Interface(object=bus.get_object(bus_name="org.bluez", object_path="/org/bluez/hci0/dev_30_AE_A4_12_CB_56"),
                            dbus_interface="org.bluez.Device1")

print(interface)
result = interface.Connect()
print(result)

