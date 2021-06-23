import dbus
from dbus.mainloop.glib import DBusGMainLoop
from gi.repository import GLib

DBusGMainLoop(set_as_default=True)
loop = GLib.MainLoop()
bus = dbus.SessionBus()

def handler(signal):
    print("receive Signal:{0}".format(signal))

proxy = dbus.Interface(bus.get_object(bus_name="com.gdbus.demo", object_path="/com/gdbus/demo"), dbus_interface="com.gdbus.demo")
ret = proxy.SetName("This is designed by Apple in Cal.")
print(ret)
proxy.connect_to_signal("SendSignal", handler)

loop.run()