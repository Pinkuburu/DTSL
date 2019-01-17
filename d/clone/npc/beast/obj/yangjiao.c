
#include <weapon.h>

inherit SWORD;

void create()
{
	set_name("羊角", ({ "yang jiao","jiao" }) );
	set_weight(300);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("material", "iron");
		set("wield_msg", "$N拿起$n握在手中。\n");
		set("unequip_msg", "$N将手中的$n放回了腰间。\n");
	}
	init_sword(30,30,30);
	setup();
}
