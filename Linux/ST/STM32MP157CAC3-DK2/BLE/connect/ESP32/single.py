import dbus

if __name__ == '__main__':
    bus = dbus.SystemBus()
    remote = dbus.Interface(object=bus.get_object("org.bluez", "/"), dbus_interface="org.freedesktop.DBus.ObjectManager")
    objects = remote.GetManagedObjects()
    print(objects)
    for o, props in objects.items():
        print("object:{0} -- interface:{1}".format(o, props.keys()))
        for i in props.keys():
            print("\tkeys:{1}".format(o, i))

