
#include <armor.h>
#include <ansi.h>
inherit HANDS;

void create()
{
   set_name(HIW"手套"NOR, ({ "shoutao"}) );
   set_weight(100);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("long","这是一副普通的手套。\n");
     set("material", "毛线");
     set("unit", "副");
     set("value",80);
     set("armor_prop/armor",2);
   }
   setup();
}
