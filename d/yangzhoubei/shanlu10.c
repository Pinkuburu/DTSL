
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","山路");
  set ("long", @LONG
这里是条山路。东边是一片树林。不知道里面有没有盗贼。东边不
远就是长白山了。
LONG);

  set("exits", ([ 
 "east":__DIR__"shulin2",
 "northwest":__DIR__"shanlu9",
        ]));
  set("outdoors","yangzhoubei");
  
  set("valid_startroom", 1);
  setup();
 
}

