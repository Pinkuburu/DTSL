
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",GRN"书房"NOR);
  set ("long", @LONG
这里是李官员的书房。他办理为王世充招募人才的工作。洛阳在目
前战乱之中还算很好，所以来投奔王府的江湖豪侠很是不少。只见这里
摆了几张桌子，李官员正和几位江湖豪侠谈论着什么。
LONG);

  set("exits", ([ 

  "east":__DIR__"zoulang2",
  

       ]));
  set("objects",([
	  __DIR__"npc/li":1,
	  ]));
  

  
  set("valid_startroom", 1);
  setup();
 
}

