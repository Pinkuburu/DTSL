
#include <weapon.h>
#include <ansi.h>
inherit DAGGER;

void create()
{
	set_name(HIW"白玉短刺"NOR, ({ "baiyu duanci","duanci","dagger" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("no_save",1);
		set("long", "这是一把白玉短刺。\n");
		set("value", 50);
		set("rumor",1);
		set("super",5);
		set("material", "steel");
	}
	init_dagger(4,20,20);


	set("wield_msg", "$N从怀中摸出一把$n握在手中。\n");
	set("unwield_msg", "$N将手中的$n藏入怀中。\n");


	setup();
}
