
#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
   set_name(YEL"道袍"NOR, ({ "cloth"}) );
   set_weight(5000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("material", "cloth");
     set("long","这是一件普通的道袍。\n");
     set("unit", "件");
     set("value", 40);
     set("armor_prop/armor", 20);
   }
   setup();
}
