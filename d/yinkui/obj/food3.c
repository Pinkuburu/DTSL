
 
inherit ITEM;
inherit F_FOOD;

#include <ansi.h>

void create()
{
   set_name(HIB"青蛇"NOR, ({"qing she","she"}));
        set_weight(100);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "这是一条青蛇，在药酒中浸泡过，可以食用。\n");
                set("unit", "条");
                set("food_remaining", 10);
                set("food_supply", 50);
        }
}

