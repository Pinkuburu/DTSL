
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","坟地");
  set ("long", @LONG
这里是一座坟场。看起来有一百来个坟吧。你不禁打了个寒战！旁
边有几棵大树，树枝已经凋零，上面零散地落着几只乌鸦，朝着天空哑
哑地叫着。
LONG);

  set("exits",([
	  
	  "southeast":__DIR__"xiaolu2",
	  ]));
  set("outdoors","yinkui");
  set("valid_startroom", 1);
  setup();
 
}

