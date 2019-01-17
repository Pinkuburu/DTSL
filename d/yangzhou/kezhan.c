
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","安福客栈");
  set ("long", @LONG
这里是一家客栈，也是扬州最大的客栈了。每天都有很多人来这里
投宿。这里也是扬州热闹的地方之一，四方的游人在这里谈天说地。许
多人在那里边吃饭喝茶边小声地谈论如今天下大乱的形式；还有几个武
林人士在那里谈论着和氏璧的事情。店小二则跑来跑去，忙个不停。
LONG);

  set("exits", ([ 
 "south":__DIR__"xidajie3",
 "up":__DIR__"wofang",
        ]));
  set("objects",([
	  __DIR__"npc/xiaoer2":1,
	  ]));
  set("valid_startroom", 1);
  setup();
 
}

int valid_leave(object me,string dir)
{
	if(!me->query_temp("gived_money")&&dir=="up")
		if(objectp(present("xiao",environment(me))))
			return notify_fail("店小二拦住了你：客官，您还没给钱呢!\n");
		else return notify_fail("掌柜从里面喊道：客官，给钱再住店啊!\n");
		return ::valid_leave(me,dir);
		return 1;
}
