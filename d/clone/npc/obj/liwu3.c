
 
inherit ITEM;
inherit F_FOOD;
#include <ansi.h>
void create()
{
   set_name(HIY"香酥鲤鱼"NOR, ({"xiangsu liyu","liyu","fish"}));
        set_weight(50);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "这是武林侠侣结婚酒席中的一道菜。\n");
                set("unit", "条");
                set("no_sell",1);
                set("value", 60);
                set("no_decay",1);
                set("food_remaining",50);
                set("food_supply",80);
        }
}

