import gi
gi.require_version("Gtk", "3.0")
from gi.repository import Gtk

if __name__ == '__main__':

    text = """
        终日忙碌只为饥，才得饱来便思衣。
        绫罗绸缎买几件，回头看看房屋低。
        高楼大厦盖几座，房中又少美貌妻。
        娶下娇妻并美妾，恨无田地少根基。
        置得良田千万顷，出入无轿少马骑。
        骡马成群轿已备，叹无官职被人欺。
        县丞主簿不愿做，想要朝中挂紫衣。
        五品六品他嫌小，三品四品还嫌低。
        当朝一品为宰相，还想面南去登基。
        心满意足为天子，更望万世无死期。
        人心不足蛇吞象，不种善根费心机。
        若要世人心满足，除非南柯一梦兮。
    """

    window = Gtk.Window()

    window.set_title(title="mongoose OS")
    window.set_default_size(480, 320)

    label = Gtk.Label(text)
    window.add(label)

    window.connect("destroy", Gtk.main_quit)
    window.show_all()

    Gtk.main()
