
 
inherit ITEM;
inherit F_FOOD;

#include <ansi.h>

void create()
{
   set_name(BLU"黑蝎子"NOR, ({"xie zi","xie"}));
        set_weight(100);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "这是一只黑蝎子，在药酒中浸泡过，可以食用。\n");
                set("unit", "只");
                set("food_remaining", 10);
                set("food_supply", 50);
        }
}

