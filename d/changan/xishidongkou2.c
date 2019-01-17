
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","西市东口");
  set ("long", @LONG
这里就是位于永安大街上的闻名长安的西市－利人市的东口，十字
路口向西，就能走到热闹非凡的西市。东面是一所漂亮的园林，好像有
高门大户住在里面。
LONG);

  set("exits", ([ 
 "north":__DIR__"xishidongkou1",
 "south":__DIR__"yadajie1",
 "westup":__DIR__"ymqiao",
 "east":__DIR__"xijiyuan",
        ]));
  
  set("outdoors","changan");
  set("valid_startroom", 1);
  setup();
 
}

