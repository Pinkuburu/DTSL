
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","中央广场");
  set ("long", @LONG
这里是巴绫的中心了，这里比较繁华，行人也很多。来来往往很多
行人，熙熙攘攘，好不热闹。有几名巴陵帮的弟子走来走去。这里打把
势、卖艺的三五成群，好不热闹。几个官兵正在这里看查着情况。
LONG);

  set("exits", ([ 

  "southwest":__DIR__"xijie1",
  "southeast":__DIR__"dongjie1",
  "north":__DIR__"qingshilu1",
       ]));
 set("objects",([
	 __DIR__"npc/bing2":1,
	 __DIR__"npc/bldizi":1,
	 ]));
set("outdoors","baling");
  
  set("valid_startroom", 1);
  setup();
 
}

