// male3-cloth.c
//
// This is the basic equip for players just login.

#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
        set_name( BLK "黑色劲装" NOR, ({ "cloth" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
		set("long", "一件很笔挺的黑色劲装。\n");
                set("material", "cloth");
		set("value", 0);
                set("armor_prop/armor", 1);
              set("no_give", "随身的东西不能给人。\n");

        }
        setup();
}

