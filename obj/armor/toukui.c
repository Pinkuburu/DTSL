
#include <armor.h>
#include <ansi.h>
inherit HEAD;

void create()
{
   set_name(HIG"头盔"NOR, ({ "tou kui","kui"}) );
   set_weight(600);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("long","这是一件铁制的头盔。\n");
     set("material", "铁");
     set("unit", "顶");
     set("value",100);
     set("armor_prop/armor",30);
   }
   setup();
}
