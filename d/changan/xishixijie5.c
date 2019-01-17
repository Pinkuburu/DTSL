
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","西市西街");
  set ("long", @LONG
你来到了闻名长安的西市－利人市，这里是利人市的西街，到处都
是前来逛集市的人。吆喝声，叫卖声不绝于耳，西面有一家鲜花店，东
面是一个钱庄。
LONG);

  set("exits", ([ 
  "north":__DIR__"xishixijie4",
  "south":__DIR__"xishinankou1",
 "west":__DIR__"huadian1",
 "east":__DIR__"qianzhuang1",
        ]));
  set("objects",([
         __DIR__"npc/liumang":2,
         ]));
  set("outdoors","changan");
  set("valid_startroom", 1);
  setup();
 
}

