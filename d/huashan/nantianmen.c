
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","南天门");
  set ("long", @LONG
南天门在南峰东侧。自东峰南坡下经二仙龛、紫气台，沿崎岖小径
攀援即达。为登临朝元洞、长空栈道、贺老石室、全真崖的必由之道。
LONG);

  set("exits", ([ 
 "northwest":__DIR__"shanlu4",
 "southeast":__DIR__"shanlu2",
       ]));
  /*
  set("objects",([
	  __DIR__"npc/yao":1,
	  ]));*/
   set("valid_startroom", 1);
   set("outdoors","huashan");
  setup();
 
}
