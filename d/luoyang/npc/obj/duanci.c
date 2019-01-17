
#include <weapon.h>
//#include <ansi.h>
inherit DAGGER;

void create()
{
	set_name("短刺", ({ "dagger" }) );
	set_weight(400);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long","这是一把短刺，小巧灵活。\n");
		set("value",500);
		set("material", "steel");
	}
	init_dagger(15,60,60);

	set("wield_msg", "$N「唰」地一声从怀中抽出一把$n握在手中。\n");
	set("unwield_msg", "$N将手中的$n放入怀中。\n");

	setup();
}
