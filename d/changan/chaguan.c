

#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","茶馆");
  set ("long", @LONG
这间茶房是长安的闲人杂聚的场所，里面横七竖八的摆放着一些木
制的桌椅。一个说书的老人正在滔滔不绝的讲着什么。一些茶客一边品
茶，一边听书，一边绘声绘色交头接耳，如果你要想打听江湖掌故和谣
言，来这里准没错。
LONG);

  set("exits", ([ 
 "east":__DIR__"dongshidongjie3",
        ]));
  set("objects",([
	  __DIR__"npc/cha":1,
	  ]));
  set("resource/water",1);
  set("valid_startroom", 1);
  setup();
 
}

