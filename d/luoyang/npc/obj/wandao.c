
#include <weapon.h>
#include <ansi.h>
inherit BLADE;

void create()
{
	set_name(HIW"弯刀"NOR, ({ "wan dao","wan","dao","blade" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long","这是一把劣弧形状的弯刀。\n");
		set("value",1500);
		set("material", "steel");
	}
	init_blade(60,100,100);

	set("wield_msg", "$N「唰」地一声抽出一把$n握在手中。\n");
	set("unwield_msg", "$N将手中的$n插入腰间的刀鞘。\n");

	setup();
}
