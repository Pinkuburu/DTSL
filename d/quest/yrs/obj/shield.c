
#include <armor.h>
#include <ansi.h>
inherit SHIELD;

void create()
{
   set_name(HIG"护盾"NOR, ({ "shield"}) );
   set_weight(200);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("long","这是一个铁打的护盾。\n");
     set("material", "铁");
     set("unit", "个");
     set("value",200);
     set("armor_prop/armor",30);
   }
   setup();
}
