

#include <ansi.h>

inherit ITEM;

void create()
{
   set_name(HIY"藏宝图"NOR, ({ "cangbao tu","tu" }) );
   set_weight(100);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("unit", "张");
     set("give_lianrou",1);
     set("material", "paper");
     set("long", "这是一张藏宝图，上面画的好象是扬州的广场。\n");
     
   }
   setup();
}
