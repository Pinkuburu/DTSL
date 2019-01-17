
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","中心广场");
  set ("long", @LONG
这里是杭州的中心了。这里是杭州最热闹的地方了，汇集了五湖四
海的游客，熙熙攘攘，好不热闹。许多游客都朝着西边的西湖走去，街
头还有很多卖花的小姑娘。你不禁为这里的热闹气氛所感染了。
LONG);

  set("exits", ([ 

  "south":__DIR__"nandajie1",
  "north":__DIR__"beidajie2",
  "west":__DIR__"xidajie1",
  "east":__DIR__"dongdajie1",
         ]));
  set("objects",([
	  __DIR__"npc/youke1":1,
	  __DIR__"npc/guniang":1,
	  ]));

set("outdoors","hangzhou");
  
  set("valid_startroom", 1);
  setup();
 
}

