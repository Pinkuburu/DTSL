
#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
   set_name(HIW"白纱衣"NOR, ({ "cloth","yi" }) );
   set_weight(5000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("material", "cloth");
	 set("long","这是一件白色的纱衣\n");
     set("unit", "件");
     set("value", 40);
     set("armor_prop/armor", 2);
   }
   setup();
}
