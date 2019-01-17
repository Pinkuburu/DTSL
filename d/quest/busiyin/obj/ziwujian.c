

#include <weapon.h>
#include <ansi.h>
inherit SWORD;

void create()
{
	set_name(HIW"子午剑"NOR, ({ "ziwu jian","jian","sword" }));
	set_weight(2000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("long", "这是邪教高手左游仙的兵器。\n");	
		set("no_save",1);
		set("material", "steel");
		set("wield_msg", "$N“唰”地一声抽出$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n插回剑鞘中。\n");
	}
	init_sword(60,80,80);
	setup();
}
