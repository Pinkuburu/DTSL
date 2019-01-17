
#include <ansi.h>

inherit ROOM;


void create ()
{
  set ("short","卧室");
  set ("long", @LONG
这里是宋玉致的卧室了。卧室看起来很整洁。床上的被褥叠得整整
齐齐。房间的物品摆放的很整齐，淡淡的少女清香扑鼻而来。卧室的正
中央放着一张大桌子，桌子放着一本没有看完的书。卧室内的摆设不是
很豪华，但每一样物品都是独具匠心，无一不是珍贵之品。
LONG);

  set("exits", ([ 

  "west":__DIR__"caodi2",
    ]));
  set("objects",([
        __DIR__"npc/songyuzhi":1,
	  ]));

  set("valid_startroom", 1);
  setup();
 
}

