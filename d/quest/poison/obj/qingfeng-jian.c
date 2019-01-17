// 青锋剑。

#include <weapon.h>
#include <ansi.h>
inherit SWORD;

void create()
{
	set_name(HIC"青锋剑"NOR, ({ "qingfeng jian", "jian" }));
	set_weight(3000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("long", "这是[影子刺客]杨虚延的武器。\n");
		set("value", 1500);
		set("rumor",1);
		set("super",4);
		set("material", "steel");
		set("wield_msg", "$N「唰」的一声抽出一柄$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n插回剑鞘。\n");
	}
	init_sword(280,320,320);
	setup();
}
