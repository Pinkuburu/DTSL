
#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
   set_name(BLU"蓝色舞衣"NOR, ({ "cloth"}) );
   set_weight(5000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("long","这是一件漂亮的舞衣。\n");
     set("material", "cloth");
     set("unit", "件");
     set("armor_prop/armor", 2);
   }
   setup();
}
