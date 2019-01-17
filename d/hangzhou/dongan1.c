
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","西湖东岸");
  set ("long", @LONG
这里是西湖的东岸。西湖就在你的眼前，几叶扁舟驶于湖上，点点
荷花缀于湖中。不时有歌声从湖中的画舫上传出，悦耳动听。这里的游
客很多，你不禁为这里的景色所深深吸引。
LONG);

  set("exits", ([ 
 "north":__DIR__"dongan2",
  "east":__DIR__"xidajie2",
  "southwest":__DIR__"dongan3",
  "southup":__DIR__"qiao",
         ]));
  set("objects",([
	  __DIR__"npc/youke2":1,
	  ]));

set("outdoors","hangzhou");
  
  set("valid_startroom", 1);
  setup();
 
}

