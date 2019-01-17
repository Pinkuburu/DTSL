
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","土路");
  set ("long", @LONG
这里是条土路。这里风景秀丽，山水如画，空气清新。地上有很多
漂亮的野花、蒲公英等植物。不时有野兔从你的脚旁跳过。这里地势一
片空阔，四处望去一片平坦。这里的人很少，只是偶尔有人骑着马跑过
去。
LONG);

  set("exits", ([ 

  "southwest":__DIR__"tulu1",
 "north":__DIR__"huanghe_dukou1",
 "east":"/d/mangshan/shanlu1",
         ]));
set("outdoors","luoyang");
  set("valid_startroom", 1);
  setup();
 
}

