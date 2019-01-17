
#include <weapon.h>
//#include <ansi.h>
inherit HAMMER;

void create()
{
	set_name("大铁锤", ({ "hammer" }) );
	set_weight(9000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long","这是一把大铁锤，看起来有些沉重。\n");
		set("value", 1200);
		set("material", "steel");
	}
	init_hammer(50,160,160);

	set("wield_msg", "$N「呼」地一声抽出一把$n握在手中。\n");
	set("unwield_msg", "$N将手中的$n放到了地上。\n");

	setup();
}
