
inherit ITEM;
#include <ansi.h>
void create()
{
        set_name(YEL"石蜡"NOR, ({"shila"}));
        set_weight(50);
        if (clonep())
                set_default_object(__FILE__);
    else  {
           set("unit", "块");
           set("value",200);
           set("yrs","shila");
           set("long", "这是一块石蜡．\n");
        }
}


