
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","石路");
  set ("long", @LONG
这里是净念禅院的石路。净念禅院的建筑均以三彩琉璃瓦覆盖，色
泽如新，却不知是因寺内和尚勤于打扫，还是瓦质如此。尤以三彩中的
孔雀蓝色最为耀眼。
LONG);

  set("exits", ([ 
	  "out":__DIR__"miaodoor",
	  "east":__DIR__"shilu2",
  
         ]));
  set("objects",([
	  __DIR__"npc/budian":1,
	  ]));
  set("outdoors","chanyuan");
  set("valid_startroom", 1);
  setup();
 
}

