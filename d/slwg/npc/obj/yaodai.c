
#include <armor.h>
//#include <ansi.h>
inherit WAIST;

void create()
{
   set_name("腰带", ({ "yao dai","dai","waist"}) );
   set_weight(300);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("material", "帆布");
     set("long","这是一条普通的腰带。\n");
     set("unit", "条");
     set("value",80);
     set("armor_prop/armor",5);
  }
   setup();
}
