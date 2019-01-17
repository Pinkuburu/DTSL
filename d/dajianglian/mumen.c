
#include <ansi.h>
inherit ROOM;
void create ()
{
  set ("short","木门");
  set ("long", @LONG
你来到了一个木门前，有几个守侯在木门旁边。有很多人从里面出
出进进。你仔细一看，发现旁边立着一块牌子(pai)。
LONG);

  set("exits", ([ 
	  "north":__DIR__"caodi",
	  "south":"/d/jiujiang/wguanlu2",
    ]));
set("outdoors","dajiang");
  set("objects",([
	  __DIR__"npc/dizi":2,
	  ]));
  set("item_desc",([
      "pai":HIG"大江联分舵\n"NOR,
      ]));
  set("valid_startroom", 1);
  setup();
"/obj/board/dajiang_b.c"->foo();
 
}

int valid_leave(object me,string dir)
{
   if(me->query("shili/name")!="dajiang_b"
     &&dir=="north"&&!wizardp(me)
     &&present("di zi",environment(me)))
     return notify_fail("弟子拦住了你：嘿，想进大江联要先过我这一关！\n");
     return ::valid_leave(me,dir);
}
     
