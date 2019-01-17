
#include <weapon.h>
#include <ansi.h>
inherit HAMMER;

void create()
{
   set_name(HIY"金锤"NOR, ({ "hammer" }) );
   set_weight(10000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("unit", "柄");
     set("value", 500);
     set("material", "iron");
     set("long", "这是一柄金锤，看起来好象很重。\n");
     set("wield_msg", "$N拿出$n握在手中。\n");
     set("unequip_msg", "$N将手中的$n放到地上。\n");
   }
   init_hammer(75,280,280);
   setup();
}
