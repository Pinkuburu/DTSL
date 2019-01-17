

#include <weapon.h>
#include <ansi.h>
inherit SWORD;

void create()
{
	set_name(HIG"玉箫"NOR, ({ "xiao"}));
	set_weight(1000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("long", "这是一精致的玉箫。\n");
                set("rumor",1);
		set("value", 9000);
		set("super",3);
		
	    set("material", "steel");
		set("wield_msg", "$N「唰」的一声抽出一柄$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n插回背后。\n");
	}
        init_sword(120,120,120);
	setup();
}
