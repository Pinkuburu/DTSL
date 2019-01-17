#include <weapon.h>
#include <ansi.h>
inherit BLADE;

void create()
{
	set_name(HIB"铁扇"NOR, ({ "tie shan","shan"}) );
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("value",100);
		set("material", "iron");
		set("wield_msg", "$N抽出$n,扇了几扇,握在手中。\n");
		set("unequip_msg", "$N将手中的$n插回腰间。\n");
	}
	init_blade(35,30,30);
	setup();
}
