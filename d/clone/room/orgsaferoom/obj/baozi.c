
 
inherit ITEM;
inherit F_FOOD;

void create()
{
   set_name("包子", ({"bao zi","bao"}));
        set_weight(50);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "这是一个小包子。\n");
                set("unit", "个");
                set("value", 60);
                set("food_remaining", 30);
                set("food_supply", 30);
        }
}

