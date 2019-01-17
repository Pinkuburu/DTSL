
#include <room.h>

inherit ROOM;

string look_gaoshi();
string *d=({"north","south","east"});
void create()
{
	set("short", "小树林");
	set("long", @LONG
这是一片小树林。你已经找不到出路了。
LONG
	);


	set("exits", ([
		"north" :__DIR__"youlin2",
		"south":__DIR__"youlin3",
		"west":__DIR__"wu",
		"east":__DIR__"youlin2",
	]));
       set("outdoors", "成都");
	setup();
}

int valid_leave(object me,string dir)
{
	int lev,lev2;
	lev=(int)me->query_skill("dodge",1);
	lev2=(int)me->query_skill("jiguanxue",1);
	message_vision("$N刚迈动脚步，突然不知从什么地方射来一支箭，直射向$N的眉心！\n",me);
	if(lev>=120&&lev2<120)
	{message_vision("$N连忙一闪身，躲了开来！\n",me);
		message_vision("$N觉得总是在原地打转。\n",me);
	   if(dir=="west")
	   return notify_fail("你擦了把汗，还是没找到出路。\n");
	   return ::valid_leave(me,"east");
	 
	}
	else if(lev>=120&&lev2>=120)
	{message_vision("$N连忙一闪身，躲了开来！\n",me);
	  message_vision("$N看看四下的地形，找了方向，走了过去。\n",me);
       return ::valid_leave(me,dir);
	}
	else
	{
		message_vision("冷箭直接射中$N！$N痛地几乎死去！\n",me);
		me->unconcious();
		return 0;
	}
}



