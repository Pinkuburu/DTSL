// seng-xie.c

#include <ansi.h>
#include <armor.h>

inherit BOOTS;

void create()
{
	set_name( CYN "ɮЬ" NOR, ({ "seng xie", "xie" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "˫");
		set("long", "һ˫�������õ��಼ɮЬ��\n");
		set("value", 0);
		set("material", "boots");
		set("armor_prop/dodge", 5);
              set("no_give", "�����Ķ������ܸ��ˡ�\n");

	}
	setup();
}
