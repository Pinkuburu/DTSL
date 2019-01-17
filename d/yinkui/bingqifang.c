
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","兵器房");
  set ("long", @LONG
这里是阴癸派的兵器房。地上散乱地放着一些刀、剑等武器。旁边
还有几个工人正在打磨着兵器，他们都已经被变成了聋哑人，整日只会
工作而不会说话。旁边有几个弟子正在挑选着兵器。
LONG);
  set("exits",([
	  "south":__DIR__"lianwuchang",
	  ]));
  set("objects",([
	  __DIR__"obj/changjian":2,
	  __DIR__"obj/blade":2,
	  __DIR__"obj/whip":3,
	  ]));

  
  set("valid_startroom", 1);
  setup();
 
}

