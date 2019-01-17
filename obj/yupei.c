// yupei.c 玉佩

#include <armor.h>
#include <ansi.h>

inherit NECK;

void create()
{
	set_name(HIC "玉佩" NOR, ({ "yu pei", "yu" }));
       	set("long", "\n这是一块淡兰色的宝玉，莹滑温润，光洁无瑕，真是稀世罕有。\n"+
         "这是月老送给天下有情男女的定情信物。\n");
	set("weight", 300);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "枚");
		set("value", 50000);
		set("material", "玉");
		set("armor_prop/armor", 2);
		set("female_only", 1);
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
