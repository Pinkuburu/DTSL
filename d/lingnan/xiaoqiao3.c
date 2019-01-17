
#include <ansi.h>

inherit ROOM;


void create ()
{
  set ("short","小桥");
  set ("long", @LONG
这里是座小桥。桥下有很多鱼儿游来游去。西边是一座花园。有几
个宋家堡的弟子正在桥上休息，悠闲地看着桥下水中的游鱼。不时有几
名弟子从你的身旁走过。
LONG);

  set("exits", ([ 

      "northeast":__DIR__"xilang2",
	  "west":__DIR__"huayuan2",
       ]));
  set("objects",([
	  "/d/clone/npc/chenzhifo":1,
	  ]));
  set("valid_startroom", 1);
  set("outdoors","lingnan");
  setup();
 
}

