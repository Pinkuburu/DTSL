
#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
   set_name(HIR"彩衣"NOR, ({ "cai yi","yi","cai"}) );
   set_weight(3000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("material", "cloth");
	 set("long","这是一件非常漂亮的彩衣.\n");
     set("unit", "件");
     set("value", 500);
     set("armor_prop/armor", 10);
   }
   setup();
}
