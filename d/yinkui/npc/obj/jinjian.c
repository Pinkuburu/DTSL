// longsword.c 长剑

#include <weapon.h>
inherit SWORD;

#include <ansi.h>

void create()
{
	set_name(HIY"金剑"NOR, ({ "jin jian", "jian","sword"}));
	set_weight(4000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("long", "这是一柄金色的小剑，看起来非常小巧玲珑。\n");
		set("value", 1500);
		set("no_save",1);
		set("material", "steel");
		set("wield_msg", "$N「唰」的一声抽出一柄$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n插回剑鞘。\n");
	}
	init_sword(20,50,50);
	setup();
}
