

#include <weapon.h>
#include <ansi.h>
inherit BLADE;

void create()
{
   set_name(HIR"霸王刀"NOR, ({ "bawang dao","blade","dao" }) );
   set_weight(4000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("unit", "柄");
     set("rumor",1);
set("no_sell",1);
     set("super",6);
     set("value", 500);
     set("material", "iron");
     set("long", "这是岳山的成名兵器。\n");
     set("wield_msg", YEL"$N抽出$n,"+YEL+"挽了个刀花，握在手中。\n"NOR);
     set("unequip_msg", "$N将手中的$n插入腰间的刀鞘。\n");
   }
   init_blade(225,280,280);
   setup();
}
