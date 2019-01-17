
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","东市东街");
  set ("long", @LONG
你来到了闻名长安的东市－都会市，这里是都会市的东街，到处都
是前来逛集市的人。吆喝声，叫卖声不绝于耳。
LONG);

  set("exits", ([ 
  "north":__DIR__"dongshidongjie3",
  "south":__DIR__"dongshidongjie5",
  "west":__DIR__"dongshixijie4",
  "east":__DIR__"dongshidongkou2",
        ]));
  set("objects",([
	  __DIR__"npc/shangren":1,
	  ]));
  set("outdoors","changan");
  set("valid_startroom", 1);
  setup();
 
}

