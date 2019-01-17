
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","西市东街");
  set ("long", @LONG
你来到了闻名长安的西市－利人市，这里是利人市的东街，到处都
是前来逛集市的人。吆喝声，叫卖声不绝于耳，东面有一家首饰店，西
面是一家药店。
LONG);

  set("exits", ([ 
  "north":__DIR__"xishibeikou2",
  "south":__DIR__"xishidongjie2",
  "west":__DIR__"baorentang",
  "east":__DIR__"shoushidian",
        ]));
  
  set("outdoors","changan");
  set("valid_startroom", 1);
  setup();
 
}

