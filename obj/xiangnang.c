// 香囊。

#include <armor.h>
#include <ansi.h>

inherit NECK;

void create()
{
	set_name(HIM "香囊" NOR, ({ "xiang nang", "nang","xiang" }));
       	set("long", "\n这是一个香囊，散发着淡淡的香气，上面还有精制的图案。\n"+
         "这是月老送给天下有情男女的定情信物。\n");
	set("weight", 300);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("value", 50000);
		set("material", "布");
		set("armor_prop/armor", 2);
		set("male_only", 1);
		set("no_get",1);
	}
	setup();
}	
int query_autoload()
{
	return 1;
}

int unequip()
{
	object ob = environment();

	if (userp(ob) && ob->query("couple/couple_id") && ob->query("couple/couple_name"))
		return notify_fail("你不能卸下你的定情信物。\n");

	return ::unequip();
}

