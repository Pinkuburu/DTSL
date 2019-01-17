
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","官路");
  set ("long", @LONG
这里是一条官路。往西边走就是长安的东门了，从这里可以遥遥望
见长安的城墙。不时有人骑着马从你的身旁驰过，看起来似乎是去投奔
长安李阀的。虽是战乱年代，但是这条官路看起来还是很太平。
LONG);

  set("exits", ([ 
"west":__DIR__"guanlu1",
"east":__DIR__"shanlu1",
        ]));
 set("outdoors","changan");
  
  set("valid_startroom", 1);
  setup();
 
}

