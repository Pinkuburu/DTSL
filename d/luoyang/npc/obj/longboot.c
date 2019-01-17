
#include <armor.h>
#include <ansi.h>
inherit BOOTS;

void create()
{
   set_name(HIG"长筒皮靴"NOR, ({ "pixue"}) );
   set_weight(500);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("material", "皮");
     set("long","这是一双从突厥进口来的皮靴。\n");
     set("unit", "双");
     set("value",1500);
     set("armor_prop/dodge",15);
   }
   setup();
}
