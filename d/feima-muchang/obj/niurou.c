
 
inherit ITEM;
inherit F_FOOD;

void create()
{
   set_name("牛腿", ({"niu tui","tui"}));
        set_weight(100);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "这是一个香气四溢的牛腿。\n");
                set("unit", "个");
                set("value", 50);
                set("food_remaining", 10);
                set("food_supply", 50);
        }
}

