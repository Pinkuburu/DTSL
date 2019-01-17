
#include <armor.h>
#include <ansi.h>
inherit ARMOR;

void create()
{
   set_name(HIG"战甲"NOR, ({ "zhan jia","zhan","jia","armor"}) );
   set_weight(2000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("material", "钢铁");
     set("long","这是一件士兵们经常穿的战甲。\n");
     set("unit", "件");
     set("value",2000);
     set("armor_prop/armor",30);
     set("armor_prop/dodge",-2);
   }
   setup();
}
