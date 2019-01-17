
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","北天街");
  set ("long", @long
这里是北天街。西面有一家洛阳著名的客栈[洛阳客栈]。店小二正
在那里热情地招呼来往的行人。南面是洛阳的中心。这里热闹非凡。往
北走可以到洛阳最大的青楼曼清院。有许多姑娘正在招呼路边的行人。
long);

  set("exits", ([ 
      "west":__DIR__"luoyang-kezhan",  
      "south":__DIR__"tianjie",
      "north":__DIR__"beijie2",
         ]));
  set("outdoors","luoyang");
  set("valid_startroom", 1);
  setup();
}

