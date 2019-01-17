
#include <weapon.h>

inherit STAFF;

void create()
{
   set_name("钢拐", ({ "guai" }) );
   set_weight(5000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("unit", "个");
     set("value", 500);
     set("material", "iron");
     set("long", "这是一个钢拐，看起来似乎不轻。\n");
     set("wield_msg", "$N拿出$n握在手中。\n");
     set("unequip_msg", "$N将手中的$n放了下来。\n");
   }
   init_staff(65,280,280);
   setup();
}
