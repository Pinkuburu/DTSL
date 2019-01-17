
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","西市东街");
  set ("long", @LONG
你来到了闻名长安的西市－利人市，这里是利人市的东街，到处都
是前来逛集市的人。吆喝声，叫卖声不绝于耳，东面是长安著名的酒楼
--福聚楼，西面有一座特别宏伟的建筑物。
LONG);

  set("exits", ([ 
  "north":__DIR__"xishidongjie2",
  "south":__DIR__"xishidongjie4",
  "west":__DIR__"xishishu",
  "east":__DIR__"fujulou",
        ]));
  set("objects",([
	  __DIR__"npc/shangren":1,
	  ]));
  set("outdoors","changan");
  set("valid_startroom", 1);
  setup();
 
}

