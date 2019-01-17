
#include <weapon.h>
#include <ansi.h>
inherit BLADE;

void create()
{
   set_name("扇子", ({ "shan zi","shan"}) );
   set_weight(1000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("unit", "把");
     set("material", "iron");
     set("no_give",1);
     set("save_flag",1);
     set("save_box",1);
     set("long", "这是一把纸扇子。\n");
     set("wield_msg", "$N拿出一把$n握在手中,随手扇了几下。\n");
     set("unequip_msg", "$N将手中的$n折起，放入怀中。\n");
   }
   init_blade(15,90,90);
   setup();
}

