
#include <ansi.h>
inherit ROOM;

int do_jump(string arg);
void create ()
{
  set ("short","水潭底");
  set ("long", @LONG
这里是水潭的底部。你睁大眼睛四处地看去，发现这里有很多的游
鱼，都长有尖锐的牙齿，看起来非常危险。这种地方还是尽早离开的好。
LONG);
 if(sizeof(children(__DIR__"obj/bawangdao"))<2)
  set("objects",([
	  __DIR__"obj/bawangdao":1,
	  "/d/clone/npc/beast/shirenyu":1,
	  ]));

set("no_clean_up",1);
  set("valid_startroom", 1);
  setup();
 
}

void init()
{
	add_action("do_jump",({"jump","tiao"}));
}

int do_jump(string arg)
{
	object me;
	me=this_player();
	if(!arg||(arg!="岸"&&arg!="up"))
		return notify_fail("你要往哪里跳？\n");
	message_vision("$N刷地一声从水中一跃而出！\n",me);
	me->move(__DIR__"shuitan");
	return 1;
}
