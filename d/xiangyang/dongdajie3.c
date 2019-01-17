
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","东大街");
  set ("long", @LONG
这里是襄阳的东街。北面是一家古董店，上面的金子招牌在阳光下
闪闪发光。南面是一家药店，店铺上的“济世救人”四个字老远就看的
清清楚楚。
LONG);

  set("exits", ([ 
 "east":__DIR__"dongmen",
 "west":__DIR__"dongdajie2",
 "north":__DIR__"gudongdian",
 "south":__DIR__"yaodian",
        ]));
  set("outdoors","xiangyang");
  
  set("valid_startroom", 1);
  setup();
 
}

int valid_leave(object me,string dir)
{
	object card;
	if(objectp(card=present("gong han",me)))
	{
		message_vision("官兵收走了$N身上的公函\n",me);
		me->delete_temp("no_in");
		destruct(card);
	}
	return ::valid_leave(me,dir);
}

