
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","洛阳客栈");
  set ("long", @LONG
这里就是洛阳客栈。这是洛阳最大的一家客栈，每天人来人往，络
绎不绝。只见客栈的门前挂着一个大红灯笼，旁边还立着一个牌匾，上
面写着出入平安四个字。店小二忙前忙后，跑个不停。
LONG);

  set("exits", ([ 
  
	  "east":__DIR__"beijie1",
	  "up":__DIR__"shuifang",
         ]));
  set("objects",([
	  __DIR__"npc/xiaoer":1,
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

