
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","山路");
  set ("long", @LONG
这里是条山路。这里是岭南了。山路崎岖，可以隐隐约约看到宋家
堡了。
LONG);

  set("exits", ([ 
 "northeast":__DIR__"shanlu1",
 "south":__DIR__"shanlu3",
         ]));
  set("outdoors","jiujiang"); 
  set("valid_startroom", 1);
  setup();
 
}

