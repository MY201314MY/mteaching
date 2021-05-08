# D-BUS

## 一、xml

```xml
<?xml version="1.0" encoding="UTF-8"?>
<node>
  <interface name="com.gdbus.demo">
    <method name="SetData">
      <arg name="data" type="s" direction="in"/>
      <arg name="response" type="s" direction="out"/>
    </method>
    <signal name="SendSignal">
      <arg name="sig" type="i"/>
    </signal>
  </interface>
</node>
```

## 二、example

​	1、bluetooth

```shell
:<<!
echo -e "\n- - - - Bluetooth / - - - -"
dbus-send --system --print-reply --dest=org.bluez / org.freedesktop.DBus.Introspectable.Introspect

echo -e "\n- - - - Bluetooth / - - - -"
dbus-send --system --print-reply --dest=org.bluez /org/bluez org.freedesktop.DBus.Introspectable.Introspect

echo -e "\n- - - - Bluetooth HCI0 - - - -"
dbus-send --system --print-reply --dest=org.bluez /org/bluez/hci0 org.freedesktop.DBus.Introspectable.Introspect

echo -e "\n- - - - Bluetooth Methods - - - -"
dbus-send --system --print-reply --dest=org.bluez / org.freedesktop.DBus.ObjectManager.GetManagedObjects

echo -e "\n- - - - Bluetooth HCI0 Properties - - - -"
dbus-send --system --print-reply --dest=org.bluez /org/bluez/hci0 org.bluez.Adapter1.GetDiscoveryFilters
!

dbus-send --system --type=method_call --print-reply --dest=org.freedesktop.DBus / org.freedesktop.DBus.ListNames
dbus-send --system --print-reply --dest=org.bluez /org/bluez org.freedesktop.DBus.Introspectable.Introspect
```

2、bus

```shell
echo -e "- - - - Queue Service in System Bus - - - -\n"
dbus-send --system --print-reply --dest=org.freedesktop.DBus /org/freedesktop/DBus org.freedesktop.DBus.ListActivatableNames

echo -e "- - - - Queue Service in Session Bus - - - -\n"
dbus-send --session --print-reply --dest=org.freedesktop.DBus /org/freedesktop/DBus org.freedesktop.DBus.ListActivatableNames

echo -e "- - - - Queue Basic Service - - - -\n"
dbus-send --system --print-reply --dest=org.freedesktop.DBus /org/freedesktop/DBus org.freedesktop.DBus.Introspectable.Introspect
```

3、cal

```
dbus-send --system --print-reply --dest=org.bluez /org/bluez/hci0 org.freedesktop.DBus.Properties.GetAll string:"org.bluez.Adapter1"
```

## 三、Makefile

```makefile
obj := client

all:
	$(CC) $(obj).c -o $(obj) `pkg-config --cflags --libs glib-2.0`                                                                              

clean:
	rm -f $(obj)
```

