
 
inherit ITEM;
inherit F_FOOD;

void create()
{
   set_name("兔腿", ({"tu tui","tui"}));
        set_weight(50);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "这是一个兔腿。\n");
                set("unit", "个");
                set("food_remaining",50);
                set("food_supply", 50);
        }
}

