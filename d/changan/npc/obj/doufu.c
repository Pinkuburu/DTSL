
 
inherit ITEM;
inherit F_FOOD;

void create()
{
   set_name("五香豆腐", ({"doufu"}));
        set_weight(100);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "这是长安的特产。\n");
                set("unit", "块");
                set("value", 90);
                set("food_remaining", 20);
                set("food_supply", 30);
        }
}

