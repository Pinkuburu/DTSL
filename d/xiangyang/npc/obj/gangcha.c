
#include <weapon.h>
//#include <ansi.h>
inherit FORK;

void create()
{
	set_name("钢叉", ({ "fork" }) );
	set_weight(800);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long","这是一把三尖钢叉。\n");
		set("value",500);
		set("material", "steel");
	}
	init_fork(15,90,90);

	set("wield_msg", "$N「唰」地一声抽出一把$n握在手中。\n");
	set("unwield_msg", "$N将手中的$n放到地上。\n");

	setup();
}
