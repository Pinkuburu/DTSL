
#include <armor.h>

inherit HEAD;

void create()
{
   set_name("钢箍", ({ "gang gu","gu"}) );
   set_weight(300);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("material", "铁");
     set("long","这是一个和尚戴的钢箍。\n");
     set("unit", "个");
     set("value",60);
     set("armor_prop/armor",3);
   }
   setup();
}
