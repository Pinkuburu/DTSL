
#include <armor.h>
#include <ansi.h>
inherit FINGER;

void create()
{
   set_name(HIY"指环"NOR, ({ "zhihuan"}) );
   set_weight(20);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("long","这是一个指环。\n");
     set("material", "铁");
     set("unit", "个");
     set("value",30);
     set("armor_prop/armor",1);
   }
   setup();
}
