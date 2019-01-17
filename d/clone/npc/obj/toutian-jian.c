#include <weapon.h>
#include <ansi.h>
inherit SWORD;
void create()
{
	set_name(HIR"偷天剑"NOR, ({ "sword","jian" }) );
	set_weight(4000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("value", 500);
		set("super",3);
		set("no_save",1);
		set("rumor",1);
		set("material", "iron");
		set("wield_msg", "$N抽出$n,顿时周围打了个闪电。\n");
		set("unequip_msg", "$N将手中的$n插入腰间的剑鞘。\n");
	}
	init_sword(225,180,180);
	setup();
}
