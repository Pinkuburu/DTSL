
 
inherit ITEM;
inherit F_FOOD;

void create()
{
   set_name("椰子", ({"ye zi","ye","zi"}));
        set_weight(100);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "这是一个椰子。\n");
                set("unit", "个");
                set("food_remaining", 10);
                set("food_supply", 50);
        }
}

