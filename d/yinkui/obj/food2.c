
 
inherit ITEM;
inherit F_FOOD;

#include <ansi.h>

void create()
{
   set_name(HIR"毒"HIY"蜘"HIB"蛛"NOR, ({"zhi zhu","zhi"}));
        set_weight(100);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "这是一个毒蜘蛛，在药酒中浸泡过，可以食用。\n");
                set("unit", "个");
                set("food_remaining", 10);
                set("food_supply", 50);
        }
}

