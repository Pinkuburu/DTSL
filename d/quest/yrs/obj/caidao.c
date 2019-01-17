#include <weapon.h>
inherit BLADE;

void create()
{
	set_name("菜刀", ({ "cai dao","dao"}) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("value",10);
		set("material", "iron");
		set("wield_msg", "$N抽出$n握在手中。\n");
		set("unequip_msg", "$N将手中的$n插回腰间。\n");
	}
	init_blade(10,20,20);
	setup();
}
