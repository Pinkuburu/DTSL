// longsword.c ����

#include <weapon.h>
inherit SWORD;

void create()
{
	set_name("����", ({ "changjian", "jian" }));
	set_weight(5000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ���ɶ����ɴ���ĸֽ���\n");
		set("super",3);
		set("value", 3000);
		set("life",20);
		set("material", "steel");
		set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n��ؽ��ʡ�\n");
	}
	init_sword(40,120,120);
	setup();
}