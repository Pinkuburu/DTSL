
 
inherit ITEM;
inherit F_FOOD;

void create()
{
   set_name("馒头", ({"man tou","tou"}));
        set_weight(100);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "这是一个雪白的馒头。\n");
                set("unit", "个");
                set("value", 50);
                set("food_remaining", 10);
                set("food_supply", 40);
        }
}

