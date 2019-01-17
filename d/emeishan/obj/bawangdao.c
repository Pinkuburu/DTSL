

#include <weapon.h>
#include <ansi.h>
inherit BLADE;

void create()
{
	set_name(GRN"霸王刀"NOR, ({ "bawang dao", "bawang","dao","blade" }));
	set_weight(5000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("long", "这是当年[霸刀]岳山所使用的刀，据说锋利无比。\n");
		set("value", 15000);
 set("no_save",1);
	    set("super",4);
		set("material", "steel");
		set("wield_msg", "$N「唰」的一声抽出$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n插回刀鞘。\n");
	}
	init_blade(30,150,150);
	setup();
}
