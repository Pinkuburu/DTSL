

#include <weapon.h>
#include <ansi.h>
inherit STAFF;

void create()
{
	set_name(HIY"独脚铜人"NOR, ({ "dujiao tongren","tongren" }));
	set_weight(7000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("long", "这是一个独脚铜人。\n");	
		set("no_save",1);
		set("material", "steel");
		set("wield_msg", "$N从后背抽出$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n插回背后。\n");
	}
	init_staff(60,150,150);
	setup();
}
