
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","福聚楼");
  set ("long", @LONG
这里就是长安最有名的酒楼了，通常一般人是没资格在这里吃饭的，
只有那些王孙公子，富贾名商，江湖名人或者一些惹不起的黑道人物才
能在这里享受。三楼的景致最好，靠东的座席更可尽览永安街和跃马桥
一带的迷人风光。
LONG);

  set("exits", ([ 
 "west":__DIR__"xishidongjie3",
        ]));
 set("objects",([
	 __DIR__"npc/xiaoer5":1,
	 ]));
  set("valid_startroom", 1);
  setup();
 
}

