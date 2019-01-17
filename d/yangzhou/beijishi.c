
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","北集市");
  set ("long", @LONG
这里是扬州城的五大集市之一北集市。这里也是扬州的热闹的地方
之一。卖东西的、卖艺的、杂耍的，各占一处，吸引了很多游人。东面
是扬州著名的一家酒楼，酒香不住地从那里传来。只听人群发出一声“
好！”，看来卖艺人的生意现在还不错。
LONG);

  set("exits", ([ 
 "northeast":__DIR__"beidajie2",
 "south":__DIR__"beidajie1",
 "east":__DIR__"zuihualou",
        ]));
  set("objects",([
	  "obj/npc/butou":1,
	  __DIR__"npc/old":1,
	  ]));
  set("outdoors","yangzhou");
  
  set("valid_startroom", 1);
  setup();
 
}

