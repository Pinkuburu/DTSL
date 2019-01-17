
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","东大街");
  set ("long", @LONG
这里是扬州城的东大街。这里的行人较多，北面是一个废弃的园子，
据说里面经常闹鬼，所以平时几乎没有人去那里。东边是是扬州的东门
，可以看到有几个官兵正把守在那里。
LONG);

  set("exits", ([ 
 "east":__DIR__"dongmen",
 "west":__DIR__"dongdajie2",
 "north":__DIR__"feiyuan",

        ]));
  set("objects",([
    "/d/clone/npc/zhangshihe":1,
    ]));
  set("outdoors","yangzhou");
  
  set("valid_startroom", 1);
  setup();
 
}

