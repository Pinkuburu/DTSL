#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
        set_name(HIW"唐装"NOR, ({ "cloth" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
		set("long", "理论上可以看到这个描述的就只有巫师吧。\n");
                set("material", "cloth");
                set("value", 0);
                set("armor_prop/armor", 3);
              set("no_give", "随身的东西不能给人。\n");

        }
        setup();
}

