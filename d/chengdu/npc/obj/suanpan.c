
#include <weapon.h>

inherit STAFF;

void create()
{
        set_name("算盘", ({"suan pan", "suan","pan"}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                set("long", "这是一个钢制算盘，是一种独门兵器．\n");
                set("value", 500);
                set("material", "iron");
                set("wield_msg","$N拿出一把$n，握在手中。\n");
                set("unwield_msg", "$N放下手中的$n。\n");
        }

        init_staff(10,80,80);
        setup();
}

