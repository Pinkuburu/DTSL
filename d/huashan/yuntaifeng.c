
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","云台峰");
  set ("long", @LONG
云台峰是华山主峰之一，因位置居北得名。北峰四面悬绝，上冠景
云，下通地脉，巍然独秀，有若云台，因此又名云台峰。峰北临白云峰，
东近量掌山，上通东西南三峰，下接沟嶂峡危道，峰头由几组巨石拼接，
浑然天成。
LONG);

  set("exits", ([ 
 "southdown":__DIR__"woniutai",
       ]));
  /*set("objects",([
	  __DIR__"npc/yao":1,
	  ]));*/
   set("valid_startroom", 1);
   set("outdoors","huashan");
  setup();
 
}
