
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","春在楼");
  set ("long", @LONG
这里是九江最著名的妓院--春在楼。门口有几位漂亮的姑娘在招揽
街上的行人。有很多公子哥儿出出进进，笑语连连。
LONG);

  set("exits", ([ 
 "west":__DIR__"beidajie2",
        ]));
  set("objects",([
	  __DIR__"npc/girl":1,
"/d/job/xiang/xiang":1,
	  ]));
  
  set("valid_startroom", 1);
  setup();
 
}

