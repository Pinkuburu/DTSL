
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","山路");
  set ("long", @LONG
这里道路崎岖，可谓是华山的险地之一。向北望去，可以看到华山
巍峨的朝阳峰。向西北望去，可以看到华山秀丽的玉女峰。南边是华山
下棋亭。
LONG);

  set("exits", ([ 
 "westup":__DIR__"shanlu5",
 "south":__DIR__"xiaqiting",
       ]));
       /*
  set("objects",([
	  __DIR__"npc/yao":1,
	  ]));*/
   set("valid_startroom", 1);
   set("outdoors","huashan");
  setup();
 
}
