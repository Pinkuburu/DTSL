
inherit ITEM;

#include <ansi.h>

void create()
{
   set_name("鱼", ({ "fish"}) );
   set_weight(4000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     
     set("unit", "条");
     set("value",100);
     set("long","这是一条鱼。\n");
    
   }
   setup();
}
