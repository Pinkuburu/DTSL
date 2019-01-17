
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","南大街");
  set ("long", @LONG
这里是襄阳的南大街。南面就是襄阳的南门了，这里的人不是很多。
东边有一个兵营，有几个官兵正靠在栅栏上打盹。不时有人赶着盐车从你
的身旁走过。
LONG);

  set("exits", ([ 
 "east":__DIR__"bingying2",
 "north":__DIR__"nandajie3",
 "south":__DIR__"nanmen",
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
