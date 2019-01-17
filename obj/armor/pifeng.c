
#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
   set_name(HIR"虎皮披风"NOR, ({ "pi feng"}) );
   set_weight(800);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("long","这是一件虎皮披风。\n");
     set("material", "虎皮");
     set("unit", "件");
     set("value", 400);
     set("armor_prop/armor",40);
   }
   setup();
}
