
#include <weapon.h>
#include <ansi.h>
inherit SPEAR;

void create()
{
	set_name(HIW"弯月银枪"NOR, ({ "spear" }) );
	set_weight(9000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long","这把枪的枪尖略弯，因而有[弯月]之称。\n");
		set("value", 4000);
		set("material", "steel");
	}
	init_spear(80,120,120);

	set("wield_msg", "$N「唰」地一声抽出一把$n握在手中。\n");
	set("unwield_msg", "$N将手中的$n放到了地上。\n");

	setup();
}
