
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","南大街");
  set ("long", @LONG
这里是扬州城的南大街。南来北往的客人很多。南边就是扬州最热
闹的集市--南集市。讨价还价和吵骂的声音充斥了整个街头。西面有一
家酒楼，飘来了阵阵的酒香，几个喝的酩酊大醉的客人的划拳声不时从
窗口传出，吵得人心烦意乱。
LONG);

  set("exits", ([ 
 "west":__DIR__"jiulou",
 "north":__DIR__"nandajie1",
 "southwest":__DIR__"nanjishi",
        ]));
  set("objects",([
	  __DIR__"npc/shangren":1,
	  "/d/clone/npc/yushiji":1,
	  ]));
  set("outdoors","yangzhou");
  
  set("valid_startroom", 1);
  setup();
 
}

