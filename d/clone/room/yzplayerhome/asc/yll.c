
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","菀兰楼");
  set ("long", @LONG
这里是兰苑夫妇的卧室，中间放着一张百鸟床，床上放着云
锻彩被。右边有一个大大的衣柜，在屋子的左边是和菀苑的梳妆
台(desk)。墙上挂着两把世间少有的名剑“沙恭达罗的眼泪”和
“菀苑”。上面就是揽星阁了。
LONG);

  set("exits", ([ 
 "south":__DIR__"xshy",
 "up":__DIR__"lxg",
      ]));
 set("valid_startroom", 1);
  setup();
 
}

