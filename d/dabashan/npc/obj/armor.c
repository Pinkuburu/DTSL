
#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
   set_name(MAG"紫磷甲"NOR, ({"zilin jia","jia","armor"}) );
   set_weight(8000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("long","这是一件上好的紫磷甲，好象已经流失江湖很久了。\n");
     set("rumor",1);
     set("material", "iron");
     set("unit", "件");
     set("value", 400000);
     set("no_sell",1);
     set("no_save",1);
     set("armor_prop/armor", 200);
   }
   setup();
}
