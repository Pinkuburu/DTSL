
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","长安当铺");
  set ("long", @LONG
这里是长安的当铺。老板冷冷地站在柜台后，对来典卖东西的人向
来毫不留情。有几个人站在那里，正在犹豫是否典卖手里的东西。
LONG);

  set("exits", ([ 
 "east":__DIR__"dongshidongjie1",
        ]));
  set("objects",([
	  __DIR__"npc/tie":1,
	  ]));
  
  set("valid_startroom", 1);
  setup();
 
}

