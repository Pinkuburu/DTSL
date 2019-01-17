
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","东市东街");
  set ("long", @LONG
你来到了闻名长安的东市－都会市，这里是都会市的东街，到处都
是前来逛集市的人。吆喝声，叫卖声不绝于耳，东面是长安胜地凌烟阁，
西面是一家茶馆。
LONG);

  set("exits", ([ 
 "north":__DIR__"dongshidongjie2",
 "south":__DIR__"dongshidongjie4",
 "west":__DIR__"chaguan",
 "east":__DIR__"lingyange",
        ]));
  
  set("outdoors","changan");
  set("valid_startroom", 1);
  setup();
 
}

