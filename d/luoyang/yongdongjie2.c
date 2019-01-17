
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","永冬大街");
  set ("long", @LONG
这里是洛阳的永冬大街。东边有一家钱庄，金字牌匾在阳光下闪闪
发光。往南走可以到洛阳皇宫的南门。
LONG);

  set("exits", ([ 
  

  "north":__DIR__"yongdongjie3",
  "east":__DIR__"qianzhuang",
  "south":__DIR__"huangchengnan",
         ]));
  set("objects",([
	  __DIR__"npc/xiake":1,
	  ]));

  set("outdoors","luoyang");
  set("valid_startroom", 1);
  setup();
 
}

