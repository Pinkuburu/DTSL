
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","西市东街");
  set ("long", @LONG
你来到了闻名长安的西市－利人市，这里是利人市的东街，到处都
是前来逛集市的人。吆喝声，叫卖声不绝于耳。
LONG);

  set("exits", ([ 
  "north":__DIR__"xishidongjie3",
  "south":__DIR__"xishidongjie5",
  "west":__DIR__"xishixijie4",
  "eastup":__DIR__"ymqiao",
        ]));
  
  set("outdoors","changan");
  set("valid_startroom", 1);
  setup();
 
}

