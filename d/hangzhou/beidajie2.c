
inherit ROOM;


void create ()
{
  set ("short","北大街");
  set ("long", @LONG
这里是杭州的北大街。南边就是杭州的中心了。从这里可以听到南
边热闹的声音。几个游客从你的身旁走过，正在谈论着这里秀丽的景色。
路边有很多杂耍的艺人，不是有叫好的声音从那里传来。
LONG);

  set("exits", ([ 

  "south":__DIR__"center",
 "east":__DIR__"yanju",
  "north":__DIR__"beidajie1",
  "west": "/d/clone/room/cityroom/hangzhou"
         ]));

set("outdoors","hangzhou");
  
  set("valid_startroom", 1);
  setup();
 
}

