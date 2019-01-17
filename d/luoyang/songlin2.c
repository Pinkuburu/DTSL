
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","松林");
  set ("long", @LONG
这里是一片松林。从这里可以看到远方的洛阳城，真是美不胜收。
这里有很多漂亮的野花，把这里点缀的美丽异常。
LONG);

  set("exits", ([ 
  "west":__DIR__"songlin",
        ]));
  set("objects",([
	  __DIR__"obj/wuhuaguo":1,
	  ]));
set("outdoors","luoyang");
  set("valid_startroom", 1);
  setup();
 
}

int valid_leave(object me,string dir)
{
	object ob;
	if(dir=="west"&&present("wuhua guo",me)&&!present("she",environment(me))
		&&!me->query_temp("temp_wu"))
	{ 
		ob=new(__DIR__"npc/she");
		ob->move(environment(me));
		me->set_temp("temp_wu",1);
		tell_object(environment(me),"突然出现一条蛇！\n");
		ob->kill_ob(me);
		return notify_fail("你被蛇拦住了去路!\n");
	}
	return ::valid_leave(me,dir);
}



