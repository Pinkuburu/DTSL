
inherit ITEM;
#include <ansi.h>

void create()
{
   set_name(HIR"公函"NOR, ({ "gong han","han" }));
   set_weight(100);
   set("unit", "封");
   set("long","这是襄阳城为了运盐特批的公函.\n");
   set("value", 0);
   
}

