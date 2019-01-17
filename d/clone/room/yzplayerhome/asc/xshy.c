
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","相思花园");
  set ("long", @LONG
这里是兰菀家的花园，只见假山林立，绿柳成阴，到处都是
芍药，牡丹，玫瑰，百合，简直就是花的海洋。只见花间彩蝶飞
舞，树上百灵唱歌，水间鲤鱼游动，真是天上人间。从这往北走
过长长的甬路就是菀兰楼。
LONG);

  set("exits", ([ 
 "south":__DIR__"xsl",
 "north":__DIR__"yll",
      ]));
  set("outdoors","emeishan");
 set("valid_startroom", 1);
  setup();
 
}

