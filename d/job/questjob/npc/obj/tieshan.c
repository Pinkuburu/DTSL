
#include <weapon.h>
#include <ansi.h>
inherit BLADE;

void create()
{
   set_name("美人扇", ({ "shan zi","shan" }) );
   set_weight(3000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("unit", "把");
     set("value", 500);
     set("material", "iron");
     set("long", "这是一把美人扇，上面画着当今江湖中所有美女的画像，甚至包括师妃喧的画像。\n");
     set("wield_msg", "$N拿出一把$n握在手中,随手扇了几下。\n");
     set("unequip_msg", "$N将手中的$n折起，放入怀中。\n");
   }
   init_blade(50,100,100);
   setup();
}
