
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",GRN"南门"NOR);
  set ("long", @LONG
这里是合肥的南门。这里的行人不少。这里有几个官兵正在检查来
往的百姓。旁边还站着几个军官，耀武扬威地站在那里，不停地指手画
脚。
LONG);

  set("exits", ([ 

  "north":__DIR__"nandajie3",
  "south":__DIR__"xiaojing1",
       ]));
  set("objects",([
	  __DIR__"npc/bing":2,
	  ]));
set("outdoors","hefei");
  
  set("valid_startroom", 1);
  setup();
 
}

