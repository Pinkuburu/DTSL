
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","山景居");
  set ("long", @LONG
这里是一间茶铺，在洛阳非常有名气。这里卖的是金刚台生产的一
等黄芽叶，洛阳只此一家。现在生意非常好，很多茶客在这里喝茶聊天，
茶铺小二忙个不停。
LONG);

  set("exits", ([ 
  "west":__DIR__"baihujie3",
         ]));
  set("objects",([
	  __DIR__"npc/chaguan_laoban":1,
	  ]));
  set("valid_startroom", 1);
  set("resource/water",1);
  setup();
 
}

