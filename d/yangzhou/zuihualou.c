
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","醉花楼");
  set ("long", @LONG
这里是扬州城的的著名的酒楼--醉花楼。来到扬州的江湖豪客，都
要来这里显示一下自己。这里每天都是热热闹闹。店小二跑来跑去，忙
个不停。几个喝醉的江湖豪客正在那里高声谈论着和氏璧的事情，旁边
还有几个官兵在打量着他们。
LONG);

  set("exits", ([ 
 "west":__DIR__"beijishi",
        ]));
  set("objects",([
	  __DIR__"npc/zhao":1,
	  __DIR__"npc/xiaoer":1,
	 
	  ]));
  set("valid_startroom", 1);
  set("no_fight",1);
  setup();
  "/obj/board/pal_b.c"->foo();
 
}

