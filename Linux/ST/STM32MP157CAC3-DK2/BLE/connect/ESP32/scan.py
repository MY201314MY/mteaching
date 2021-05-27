#!/usr/bin/env python3

import dbus
from dbus.mainloop.glib import DBusGMainLoop
from gi.repository import GLib
from time import sleep

DBusGMainLoop(set_as_default=True)

loop = GLib.MainLoop()

systembus = dbus.SystemBus()

scantime = 10

def interfaces_added(object, interfaces):
    target = False
    for interface, properties in interfaces.items():
        for prop, value in properties.items():
            print("\t%s = %s" % (prop, value))
            if prop == "Name":
                if value == "espressif":
                    target = True
    if target == True:
        print("Found the target bluetooth device!")
        loop.quit()
        print("---Stop To Scan---")


def interfaces_removed(object, interfaces):
    print("device (object path) removed : %s\n" % object)
    print("\tremoved interfaces : ")
    for interface in interfaces:
        print("\t\t%s" % interface)
    print()

def discovery(switch):
    adapter1_proxy = dbus.Interface(systembus.get_object('org.bluez', '/org/bluez/hci0'), 'org.bluez.Adapter1')
    if switch == "start":
        adapter1_proxy.StartDiscovery()
        print("Discovery started!")
    if switch == "stop":
        adapter1_proxy.StopDiscovery()
        print("Discovery stoped!")
    sleep(1)

def quit():
    loop.quit()

systembus.add_signal_receiver(interfaces_added,
                              dbus_interface="org.freedesktop.DBus.ObjectManager",
                              signal_name="InterfacesAdded")

systembus.add_signal_receiver(interfaces_removed,
                              dbus_interface="org.freedesktop.DBus.ObjectManager",
                              signal_name="InterfacesRemoved")

discovery("start")

GLib.timeout_add_seconds(scantime, quit)

loop.run()

print("\nloop finished program continuing!\n")

discovery("stop")
