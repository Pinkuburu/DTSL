#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
   set_name(HIR"��ʿ��װ"NOR, ({ "cloth" }) );
   set_weight(1000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("unit", "��");
     set("material", "cloth");
     set("armor_prop/armor", 15);
   }
   setup();
}