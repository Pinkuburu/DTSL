
#include <armor.h>

inherit CLOTH;

void create()
{
   set_name("稠袍", ({ "cloth"}) );
   set_weight(5000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("long","这是一个做工讲究的稠袍.\n");
     set("material", "cloth");
     set("unit", "件");
     set("value", 40);
     set("armor_prop/armor", 2);
   }
   setup();
}
