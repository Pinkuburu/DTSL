
#include <armor.h>
#include <ansi.h>
inherit BOOTS;

void create()
{
   set_name(HIY"官靴"NOR, ({ "guan xue","xue"}) );
   set_weight(5000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("material", "leather");
	 set("long","这是当官的人所穿的靴子\n");
     set("unit", "件");
     set("value", 40);
     set("armor_prop/armor", 10);
      set("armor_prop/dodge", 10);
   }
   setup();
}
