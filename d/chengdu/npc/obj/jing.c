
#include <ansi.h>
inherit ITEM;
int do_chakan(string arg);
void create()
{
   set_name("通灵镜", ({"tongling jing","jing"}));
        set_weight(100);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "这是可以查看别人生死的通灵镜。\n");
                set("unit", "个");
                set("treatures",1);
        }
}

void init()
{
	add_action("do_chakan","chakan");
}

int do_chakan(string arg)
{
	object me,ob;
	me=this_player();
	if(!arg||!objectp(ob=present(arg,environment(me))))
		return notify_fail("你要查看谁？\n");
	message_vision(HIR"$N在$n面前祭起[通灵镜]，上面慢慢浮现出一个数字。\n"NOR,me,ob);
	tell_object(me,"通灵镜告诉你："+ob->name()+"已经死亡了"+chinese_number(ob->query("deadtimes"))+"次\n");
	tell_room(environment(me),"通灵镜啪地一声碎掉了！\n");
	destruct(this_object());
	return 1;
}
