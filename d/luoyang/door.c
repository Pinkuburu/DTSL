
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",GRN"皇宫大门"NOR);
  set ("long", @LONG
这里就是皇宫的大门，也就是天门。历代的皇帝都居住在这里。这
里站着几个官兵，打量着来往的人们。
LONG);

  set("exits", ([ 
  
  "north":__DIR__"guangchang2",
  "south":__DIR__"xiangwangjie2",
         ]));
  set("objects",([
	  __DIR__"npc/guanbing":2,
	  __DIR__"npc/duguce":1,
	  ]));
  set("outdoors","luoyang");
  set("valid_startroom", 1);
  setup();
 
}

int valid_leave(object me,string dir)
{
	if(me->query("shili")!="dugu"&&dir=="north"&&objectp(present("bing",environment(me)))&&!wizhood(me))
		return notify_fail("官兵拦住了你，大声说道：非皇家人士不得入内!\n");
	return ::valid_leave(me,dir);
}

