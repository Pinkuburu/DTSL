
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","巨灵足");
  set ("long", @LONG
登上西峰，必须经过一道陡峭和狭窄脊岭。在岭旁靠西处，有一石
窝，像似足迹，长三尺，深两寸，刻有“巨灵足”三字。传说是巨灵神
留下的足迹。
LONG);

  set("exits", ([ 
 "eastdown":__DIR__"cuilinggong",
 "westup":__DIR__"lianhuafeng",
 "southup":__DIR__"liandanlu",
       ]));
  /*set("objects",([
	  __DIR__"npc/yao":1,
	  ]));*/
   set("valid_startroom", 1);
   set("outdoors","huashan");
  setup();
 
}
