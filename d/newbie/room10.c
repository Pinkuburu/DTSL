
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","门派篇");
  set ("long", @LONG
这里是拜师学艺的第一步。你首先要使用  help menpai 来查看门
派来查看门派详细的介绍，然后再决定投入到哪个门派。在大唐中是不
允许叛师的，所以要慎重选择。拜师的命令是 bai。如你要这里的老师
为师，可以使用 bai lao。学习师傅的技能是 xue。你可以使用两种方
式来学习。一是 xue 师傅 技能的名字，二是 xue 师傅 技能名字 for
次数。对于师傅的技能，你可以使用 cha 师傅的名字来获得。
LONG);

  set("exits", ([ 
 "east":__DIR__"room11",
 "west":__DIR__"room12",
 "north":__DIR__"room13",
 "south":__DIR__"room7",
        ]));
  
  set("objects",([
       __DIR__"npc/laoshi":1,
       ]));
set("no_fight",1);
set("no_exert",1);
  set("valid_startroom", 1);
  setup();
 
}

