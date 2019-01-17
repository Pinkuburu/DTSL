

#include <weapon.h>

inherit BLADE;

void create()
{
   set_name("莲柔的刀", ({ "blade" }) );
   set_weight(4000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("unit", "柄");
     set("value", 500);
     set("material", "iron");
     set("no_in_corpse",1);
     set("nogive_player",1);
     set("lianrou_blade",1);
     set("long", "这是一柄刀，上面刻着两个小字：莲柔。\n");
     set("wield_msg", "$N抽出一把明晃晃的$n握在手中。\n");
     set("unequip_msg", "$N将手中的$n插入腰间的刀鞘。\n");
   }
   init_blade(25,80,80);
   setup();
}
