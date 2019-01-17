

#include <weapon.h>

inherit AXE;

void create()
{
	set_name("斧子", ({ "axe" }) );
	set_weight(7000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("value", 400);
		set("material", "steel");
	}
	init_axe(25,80,80);

// These properties are optional, if you don't set them, it will use the
// default values.

	set("wield_msg", "$N「唰」地一声抽出一把$n握在手中。\n");
	set("unwield_msg", "$N将手中的$n插回腰后。\n");

// The setup() is required.

	setup();
}
