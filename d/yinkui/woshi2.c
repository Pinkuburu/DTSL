
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","卧室");
  set ("long", @LONG
这里是阴癸派的教主祝玉妍的卧室。床上的被褥叠得整整齐齐。里
边摆放着一个梳妆台，旁边桌子上还放着一副没有完成的字画。左边的
墙上挂着一口宝剑。这里摆设不是十分豪华，但是但显超凡脱俗。各种
摆设井井有条，更是让人赏心悦目。
LONG);
  set("exits",([
	  "north":__DIR__"changlang",
	  ]));
  set("objects",([
 __DIR__"npc/zhuyu-yan":1,
	  ]));
  
  set("valid_startroom", 1);
  setup();
 
}

