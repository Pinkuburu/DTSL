#include <weapon.h>
#include <ansi.h>
inherit STAFF;
void create()
{
	set_name(HIY"金龙禅杖"NOR, ({ "jinlong staff","staff" }) );
	set_weight(4000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("value", 500000000000);
		set("super",5);
		set("rumor",1);
		set("no_sell",1);
		set("no_drop",1);
		set("no_give",1);
		set("material", "iron");
		set("wield_msg", YEL"$N"+YEL+"抽出$n"+YEL+",握在手中晃了几晃。\n"NOR);
		set("unequip_msg", "$N将手中的$n放到了地上。\n");
	}
	init_staff(150,400,400);
	setup();
}
