
#include <weapon.h>

inherit JIAN;

void create()
{
   set_name("锏", ({ "jian" }) );
   set_weight(4000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("unit", "柄");
     set("value", 2000);
     set("material", "iron");
     set("long", "这是一柄钢锏。\n");
     set("wield_msg", "$N拿出一柄$n握在手中。\n");
     set("unequip_msg", "$N将手中的$n插回腰间。\n");
   }
   init_jian(45,120,120);
   setup();
}
