
#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
   set_name(HIW"袈裟"NOR, ({ "jia sha","jia","sha"}) );
   set_weight(700);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("long","这是一件僧人穿的袈裟。\n");
     set("material", "丝绸");
     set("unit", "件");
     set("value", 100);
     set("armor_prop/armor",20);
     set("armor_prop/dodge",10);
   }
   setup();
}
