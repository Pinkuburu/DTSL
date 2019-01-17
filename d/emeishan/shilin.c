
#include <ansi.h>
inherit ROOM;

int do_enter(string arg);
void create ()
{
  set ("short","石林");
  set ("long", @LONG
这里是一片石林。这里寸草不生，都是怪石嶙峋的石头。北面是一
个瀑布，从这里就可以听到轰轰地声音。
LONG);

  set("exits", ([ 
 "north":__DIR__"pubu",
 "south":__DIR__"caodi1",
       ]));
   set("outdoors","emeishan");
 set("valid_startroom", 1);
  setup();
 
}

void init()
{
	add_action("do_enter",({"enter","zuan"}));
}

int do_enter(string arg)
{
	object me;
	me=this_player();
	if(!arg||(arg!="洞"&&arg!="hole"))
		return notify_fail("你要往哪里钻?\n");
	message_vision("$N看准一个洞口，朝里面使劲钻去！\n",me);
	me->move(__DIR__"hole");
	return 1;
}