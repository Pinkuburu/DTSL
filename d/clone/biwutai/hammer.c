
#include <weapon.h>

inherit HAMMER;

void create()
{
   set_name("铁锤", ({ "hammer" }) );
   set_weight(8000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("unit", "柄");
     set("value", 500);
     set("material", "iron");
     set("long", "这是一柄大铁锤，看起来分量不轻。\n");
     set("wield_msg", "$N拿出$n握在手中。\n");
     set("unequip_msg", "$N将手中的$n放在了地上。\n");
   }
   init_hammer(45,200,200);
   setup();
}
