
#include <armor.h>

inherit CLOTH;

void create()
{
   set_name("男子劲装", ({ "cloth"}) );
   set_weight(5000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("material", "cloth");
     set("unit", "件");
     set("long","这是一件练武人所穿的衣服\n");
     set("value", 40);
     set("armor_prop/armor", 2);
   }
   setup();
}
