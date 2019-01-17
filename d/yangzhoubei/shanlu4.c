
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","山路");
  set ("long", @LONG
这里是一条山路。这里的地形更加险要。旁边有很多山谷，掉下去
就是粉身碎骨了。北边是泰山了，远远可以看到泰山高耸的山峰。
LONG);

  set("exits", ([ 
 "north":__DIR__"taishanjiao",
 "southeast":__DIR__"shanlu3",
        ]));
  set("outdoors","yangzhoubei");
  
  set("valid_startroom", 1);
  setup();
 
}

