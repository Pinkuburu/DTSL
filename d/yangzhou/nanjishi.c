
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","南集市");
  set ("long", @LONG
这里是扬州城的最热闹的集市--南集市。这里熙熙攘攘，热闹非凡。
这里有很多小吃，饭店，但最出名的还是东面的一家包子店。这里有很多
卖艺的，杂耍的，不时传来呼喝叫好的声音。
LONG);

  set("exits", ([ 
 "east":__DIR__"baozidian",
 "northeast":__DIR__"nandajie2",
 "southeast":__DIR__"nandajie3",
 "west":__DIR__"zahuopu",
        ]));
  set("objects",([
	  __DIR__"npc/zhongnian":1,
	  "/d/clone/npc/feiyun":1,
	  ]));
  set("outdoors","yangzhou");
  
  set("valid_startroom", 1);
  setup();
 
}

