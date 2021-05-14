import dbus

if __name__ == '__main__':
    bus = dbus.SystemBus()
    obj = bus.get_object(bus_name="org.freedesktop.DBus", object_path="/")
    interface = dbus.Interface(object=obj, dbus_interface="org.freedesktop.DBus")

    names = interface.ListActivatableNames()

    for n in names:
        print(n)


