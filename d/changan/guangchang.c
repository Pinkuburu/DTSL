
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","朱雀广场");
  set ("long", @LONG
这里是长安城的中心了。一个很宽阔的广场，铺着青石地面。一些
游手好闲的人在这里溜溜达达，经常有艺人在这里表演。从这里向南非
常的热闹。而北面好象另外一个世界一样，非常的寂静，你不禁放轻了
脚步。
LONG);

  set("exits", ([ 
 "east":__DIR__"gmdajie4",
 "west":__DIR__"gmdajie5",
 "north": "/d/cahc/zhuquemen",
 "south":__DIR__"zqdajie3",
        ]));
  set("objects",([
	  __DIR__"npc/lijing":1,
	  ]));
 
  set("outdoors","changan");
  
  set("valid_startroom", 1);
  setup();
 
}

