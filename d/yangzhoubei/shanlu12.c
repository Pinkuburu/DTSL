
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","山路");
  set ("long", @LONG
这里是一条山路。北边是一片树林，树林看起来很大。这里已经是
安徽的境地了。望南望去，隐隐约约可以看到合肥的城墙了。
LONG);

  set("exits", ([ 
 "north":__DIR__"shulin4",
 "southwest":__DIR__"shanlu13",
        ]));
  set("outdoors","yangzhoubei");
  
  set("valid_startroom", 1);
  setup();
 
}

