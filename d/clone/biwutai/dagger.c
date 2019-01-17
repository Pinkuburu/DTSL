
#include <weapon.h>

inherit DAGGER;

void create()
{
   set_name("匕首", ({ "dagger" }) );
   set_weight(200);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("unit", "柄");
     set("value", 500);
     set("material", "iron");
     set("long", "这是一柄小匕首。\n");
     set("wield_msg", "$N拿出$n握在手中。\n");
     set("unequip_msg", "$N将手中的$n插回腰间。\n");
   }
   init_dagger(15,30,30);
   setup();
}
