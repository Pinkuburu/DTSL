//
#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
   set_name(HIY"裤头"NOR, ({ "ku tou","ku"}) );
   set_weight(600);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("material", "cloth");
     set("long","这是一件裤头，据说穿上后防御会大幅度降低！！\n");
     set("unit", "件");
     set("value", 400000);
     set("armor_prop/armor",-500);
   }
   setup();
}
