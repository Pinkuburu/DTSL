
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","襄王大街");
  set ("long", @LONG
这里是洛阳的襄王大街。西边就是洛阳的天街了。那里是洛阳最热
闹的地方了，从这里可以听到天街热闹的声音。有几个官兵从你的身旁
匆匆走过，不时打量着来往的行人。
LONG);

  set("exits", ([ 
  
  "west":__DIR__"tianjie2",
  "east":__DIR__"xiangwangjie2",
  "north":__DIR__"qingshilu1",
 
         ]));
   set("objects",([
   "/d/clone/npc/ouyang-xiyi":1,
   ]));
set("outdoors","luoyang");
  
  set("valid_startroom", 1);
  setup();
 
}

