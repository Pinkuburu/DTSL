
#include <armor.h>
#include <ansi.h>
inherit SURCOAT;

void create()
{
   set_name(HIG"战袍"NOR, ({ "zhanpao"}) );
   set_weight(100);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("long","这是一个军士打仗时穿的战袍。\n");
     set("material", "帆布");
     set("unit", "个");
     set("value",200);
     set("armor_prop/armor",30);
   }
   setup();
}
