
#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
   set_name(HIW"白衣"NOR, ({ "cai yi","cloth","yi"}) );
   set_weight(5000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("material", "cloth");
	 set("long","这是一件雪白如雪的衣服.\n");
     set("unit", "件");
     set("value", 400);
     set("armor_prop/armor", 20);
   }
   setup();
}
