
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","树林");
  set ("long", @LONG
这里是一片树林。这片树林看起来很大。南边是一条山路。那里好
象人多一些。
LONG);

  set("exits", ([ 
 "northeast":__DIR__"shulin3",
 "south":__DIR__"shanlu12",
        ]));
  set("objects",([
     __DIR__"npc/she":2,
     ]));
  set("outdoors","yangzhoubei");
  
  set("valid_startroom", 1);
  setup();
 
}

