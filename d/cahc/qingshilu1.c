
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","青石路");
  set ("long", @LONG
这是玄武门外的青石大路，道路宽敞而干净，汉白玉砌的路面被雨
水冲得光明如镜，道路两旁载着参天的古木，听到树上的小鸟时而不时
的啾鸣几声，这里到处都散发着安祥宁静的气氛。从这里向南就是掖庭
宫的后门了。
LONG);

  set("exits", ([ 
 "southup":__DIR__"houdian",
 "east":__DIR__"qingshilu2",
        ]));
 

  set("outdoors","changan");
  
  set("valid_startroom", 1);
  setup();
 
}