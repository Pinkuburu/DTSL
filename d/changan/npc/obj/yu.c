
 
inherit ITEM;
inherit F_FOOD;

void create()
{
   set_name("浇汁五味鱼", ({"fish","yu"}));
        set_weight(100);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "这是[醉花楼]的特色菜,据说此鱼有五种味道。\n");
                set("unit", "条");
                set("value", 600);
                set("food_remaining", 50);
                set("food_supply", 80);
        }
}

