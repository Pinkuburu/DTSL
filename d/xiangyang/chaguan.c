
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","茶馆");
  set ("long", @LONG
这里是襄阳的一个小茶馆。虽然是小本生意，但每天来往的客人并
不少。这里的生意还算可以。有几个茶客正坐在旁边低声地谈论着天下
的形式。店小二正专心地煮着茶。
LONG);

  set("exits", ([ 
 "east":__DIR__"beidajie3",
        ]));
 set("objects",([
	 __DIR__"npc/cha":1,
	 ]));
 set("resource/water",1);
  set("valid_startroom", 1);
  setup();
 
}

