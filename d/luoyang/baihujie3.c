
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","洛阳火坊");
  set ("long", @LONG
这里是洛阳的闹市。再往南走就上水坊桥了。有很多游人在桥上观
望，欣赏洛阳城的风光。
LONG);

  set("exits", ([ 
  
  "east":__DIR__"shanjingju",
  "northwest":__DIR__"baihujie2",
  "southup":__DIR__"baihuqiao",

         ]));
  set("objects",([
	  __DIR__"npc/rongjiaojiao":1,
	  ]));
set("outdoors","luoyang");
  
  set("valid_startroom", 1);
  setup();
 
}

