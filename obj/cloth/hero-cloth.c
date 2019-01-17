// hero-cloth.c 青色英雄氅

#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
	set_name(CYN"青色英雄氅"NOR, ({"cloth", "hero cloth"}) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("value", 0);
		set("long", "一件淡青色的英雄氅。\n");
		set("material", "cloth");
		set("armor_prop/armor", 2);
	}
	setup();
}
