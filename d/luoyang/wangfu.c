
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",GRN"王世充府"NOR);
  set ("long", @LONG
这里是洛阳城主王世充的王府。因此这里把守严密，平常人等不能
随便入内。
LONG);

  set("exits", ([ 

  "south":__DIR__"luoshenjie3",
  "enter":__DIR__"wangfu_neiting",
  "northeast":"/d/clone/room/cityroom/luoyang",

         ]));

  
  set("valid_startroom", 1);
  setup();
 
}

/*int valid_leave(object me,string dir)
{
	if((!me->query("shili")||(string)me->query("shili")!="wang")&&dir=="enter"&&!wizardp(me))
		return notify_fail("里面传来了侍卫的声音：既然不是本王府的人，就不要进来了!\n");
	return ::valid_leave(me,dir);
}*/
