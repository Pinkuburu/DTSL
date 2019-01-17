
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",HIG"安平门"NOR);
  set ("long", @LONG
这里是洛阳皇宫的西门安平门。有几个卫兵在这里把守，寻常百姓
是不能进入的。如果不是遇到大的事情，大臣们参见皇上都是从这里进
去，这里的戒备森严，官兵们正冷冷地打量着来往的行人。
LONG);

  set("exits", ([ 
  "east":__DIR__"xidian",
  "southwest":__DIR__"qingshilu1",
  "southup":__DIR__"xichenglou2",
         ]));
  set("objects",([
	  __DIR__"npc/guanbing":2,
	  ]));

  
  set("valid_startroom", 1);
  setup();
 
}

int valid_leave(object me,string dir)
{
	if(!me->query("kingdom")&&dir=="east"&&objectp(present("bing",environment(me)))&&!wizhood(me))
		return notify_fail("官兵拦住了你，大声说道：非皇家人士不得入内!\n");
	return ::valid_leave(me,dir);
}