
 
inherit ITEM;
inherit F_FOOD;
#include <ansi.h>
void create()
{
   set_name(YEL"大枣"NOR, ({"dazao"}));
        set_weight(20);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "这是一枚大枣。\n");
                set("unit", "枚");
                set("value", 20);
                set("no_decay",1);
                set("food_remaining", 10);
                set("food_supply", 10);
        }
}

