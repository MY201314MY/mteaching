import dbus
import dbus.service

if __name__ == '__main__':
    print("D-Bus version:{0}".format(dbus.__version__))

    bus = dbus.SystemBus()
    props = dbus.Interface(bus.get_object("org.bluez", "/org/bluez/hci0"), "org.freedesktop.DBus.Properties")
    print(props.GetAll("org.bluez.Adapter1"))
    props.Set("org.bluez.Adapter1", "Powered", dbus.Boolean(1))

    print(props.Get("org.bluez.Adapter1", "Address"))

    print(props.GetAll("org.bluez.Adapter1"))
    for i in props.GetAll("org.bluez.Adapter1"):
        print("key:{0} - - value:{1}".format(i, props.GetAll("org.bluez.Adapter1")[i]))
        if i == "UUIDs":
            print("UUIDs:")
            for k in props.GetAll("org.bluez.Adapter1")["UUIDs"]:
                print("    {0}".format(k.upper()))
            print("****")
    print("---End---")