
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",HIG"经房"NOR);
  set ("long", @LONG
这里是老君观的经房。里面立着几个破旧的书柜，上面落满了尘土。
书柜上放着几本道家的书籍。墙脚放着一把扫帚，也是挂满了蜘蛛网。
LONG);

  set("exits", ([ 

 "east":__DIR__"tingyuan",
         ]));

  set("valid_startroom", 1);
  setup();
 
}

