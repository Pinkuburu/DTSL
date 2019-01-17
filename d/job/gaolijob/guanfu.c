
#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
   set_name(YEL"官服"NOR, ({ "cloth"}) );
   set_weight(2000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("material", "cloth");
     set("long","这是一件高丽官兵穿的衣服。\n");
     set("unit", "件");
     set("value", 40);
     set("armor_prop/armor",10);
   }
   setup();
}
