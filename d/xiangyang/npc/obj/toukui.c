
#include <armor.h>
//#include <ansi.h>
inherit HEAD;

void create()
{
   set_name("头盔", ({ "tou kui","hui"}) );
   set_weight(500);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("material", "钢铁");
     set("long","这是士兵打仗用的头盔。\n");
     set("unit", "个");
     set("value",800);
     set("armor_prop/armor",10);
  }
   setup();
}
