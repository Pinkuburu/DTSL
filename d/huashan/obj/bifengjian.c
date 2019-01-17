
#include <weapon.h>
#include <ansi.h>
inherit SWORD;

void create()
{
	set_name(HIG"碧风剑"NOR, ({ "bifeng jian", "jian","sword" }));
	set_weight(5000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("long", "这是一柄[碧风剑]，看起来非常锋利，好象是上古的至宝。\n");
		set("value", 15000);
		set("no_save",1);
		set("super",5);
		set("material", "steel");
		set("wield_msg", "$N「唰」的一声抽出一柄$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n插回剑鞘。\n");
	}
	init_sword(40,120,120);
	setup();
}
