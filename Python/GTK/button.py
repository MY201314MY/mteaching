import gi
gi.require_version("Gtk", "3.0")
from gi.repository import Gtk


def on_button_clicked(widget):
    print("Hello World")

window = Gtk.Window()
window.set_icon_from_file("./m.jpg")
window.set_title(title="hello, world")
window.set_default_size(480, 320)

button = Gtk.Button(label="Click Here")
button.connect("clicked", on_button_clicked)
window.add(button)

window.connect("destroy", Gtk.main_quit)
window.show_all()

Gtk.main()