
 
inherit ITEM;
inherit F_FOOD;

void create()
{
   set_name("清风饭", ({"qingfeng fan","fan","baihuajian_quest_obj"}));
        set_weight(100);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "这是一团香喷喷的清风饭。\n");
                set("unit", "团");
                set("value", 100);
                set("food_remaining", 60);
                set("food_supply", 50);
        }
}

