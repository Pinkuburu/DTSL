// male2-cloth.c
//
// This is the basic equip for players just login.

#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
        set_name(BLU"青衫"NOR, ({ "qing shan", "cloth" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
		set("long", "一件很普通的粗布青衫。\n");
                set("material", "cloth");
		set("value", 0);
                set("armor_prop/armor", 1);
              set("no_give", "随身的东西不能给人。\n");

        }
        setup();
}

