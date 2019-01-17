
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","东市西街");
  set ("long", @LONG
你来到了闻名长安的东市－都会市，这里是都会市的西街，到处都
是前来逛集市的人。吆喝声，叫卖声不绝于耳。
LONG);

  set("exits", ([ 
  "north":__DIR__"dongshixijie3",
  "south":__DIR__"dongshixijie5",
  "west":__DIR__"dongshixikou2",
  "east":__DIR__"dongshidongjie4",
        ]));
  set("objects",([
   __DIR__"npc/gongzi":1,
   ]));
   
  set("outdoors","changan");
  set("valid_startroom", 1);
  setup();
 
}

