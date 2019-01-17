
#include <weapon.h>
#include <ansi.h>
inherit STAFF;

void create()
{
        set_name(HIG"碧玉杖"NOR, ({"biyu zhang", "zhang"}));
        set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "这是一条碧玉色的拐杖．\n");
                set("value", 500);
                set("no_save",1);
                set("rumor",1);
                set("material", "iron");
                set("wield_msg","$N拿出一把$n，握在手中。\n");
                set("unwield_msg", "$N放下手中的$n。\n");
        }

        init_staff(160,200,200);
        setup();
}

