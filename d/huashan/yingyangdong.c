
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","迎阳洞");
  set ("long", @LONG
此洞称“云阳”或“迎阳”洞，因向阳而名。洞内后壁上阴刻元君
像，洞顶凝露如悬殊，用器皿承接下来，叫“石乳”。洞内有很多游人
在闲逛，看起来比较热闹。
LONG);

  set("exits", ([ 
 "northwest":__DIR__"shanlu5",
       ]));
       /*
  set("objects",([
	  __DIR__"npc/yao":1,
	  ]));*/
   set("valid_startroom", 1);
   set("outdoors","huashan");
  setup();
 
}
