
#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
   set_name(HIW"��ɴ��"NOR, ({ "cloth","yi" }) );
   set_weight(5000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("material", "cloth");
	 set("long","����һ����ɫ��ɴ��\n");
     set("unit", "��");
     set("value", 40);
     set("armor_prop/armor", 2);
   }
   setup();
}