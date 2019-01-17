
#include <ansi.h>

inherit ROOM;


void create ()
{
  set ("short","卧室");
  set ("long", @LONG
这里是「天刀」宋缺的卧室。卧室看起来很整洁。床上的被褥叠得
整整齐齐。卧室的正中央放着一张大桌子，桌子上的笔墨放得很整齐，
还有一本书打开着放在上面。卧室内的摆设不是很豪华，但比起其他人
家也是不俗了，每一个物品无不是古董或名工匠的作品。
LONG);

  set("exits", ([ 

      "north":__DIR__"huayuan2",
    ]));
  set("objects",([
	  __DIR__"npc/songque":1,
	  ]));
  set("valid_startroom", 1);
 
  setup();
 
}

