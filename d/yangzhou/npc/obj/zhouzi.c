
 
inherit ITEM;
inherit F_FOOD;

void create()
{
   set_name("酱肘子", ({"jiang zhouzi","zhouzi"}));
        set_weight(200);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "这是一个酱肘子,据说用的酱已经煮了三十年了。\n");
                set("unit", "个");
                set("value",80);
                set("food_remaining",20);
                set("food_supply", 40);
        }
}

