
#include <ansi.h>
inherit ITEM;

void create()
{
   set_name(HIR"玫瑰花"NOR, ({"rose"}));
        set_weight(100);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "这是一束玫瑰花，你可以送给自己喜欢的女孩子。\n");
                set("unit", "束");
                set("value", 600);
             
        }
}

