
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","卧室");
  set ("long", @LONG
这里是阴癸派长老边不负的卧室了。床上的被褥叠得整整齐齐。墙
上挂着一柄长剑。屋中的摆设不是很多，显得有些冷清。没有特殊的允
许，没有人敢随便进入长老的卧室的。
LONG);
  set("exits",([
	  "east":__DIR__"xiaojing1",
	  ]));

  set("objects",([
	  __DIR__"npc/bianbu-fu":1,
	  ]));
  set("valid_startroom", 1);
  setup();
 
}

