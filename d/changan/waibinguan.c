
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","外宾馆");
  set ("long", @LONG
这里是长安城的外宾馆，往来到长安的人们都要住在这里，所以生
意相当红火。掌柜在旁边不停的算着帐本，店小二则跑来跑去，招呼来
往的客人忙个不停。
LONG);

  set("exits", ([ 
 "east":__DIR__"ahdajie5",
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
