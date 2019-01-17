
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","小路");
  set ("long", @LONG
这里是一条小路。两旁是高高的栅栏，里面养着各种各样的马匹。
有几个飞马牧场的人在喂养着它们。远处可以看到几个牧场，有几个飞
马牧场的弟子正在那里放牧养马。
LONG);

  set("exits", ([ 
  
	  "northwest":__DIR__"huayuan1",
	  "southeast":__DIR__"xiaolu1",
         ]));

  set("outdoors","feima");
  set("valid_startroom", 1);
  setup();
 
}

