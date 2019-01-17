
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","山路");
  set ("long", @LONG
这里道路崎岖，可谓是华山的险地之一。向东望去，可以看到华山
巍峨的朝阳峰。向北望去，可以看到华山秀丽的玉女峰。南边是华山的
迎阳洞。
LONG);

  set("exits", ([ 
 "west":__DIR__"shanlu4",
 "southeast":__DIR__"yingyangdong",
 "eastdown":__DIR__"shanlu7",
 "northup":__DIR__"shanlu6",
 "eastup":__DIR__"chaoyangfeng",
       ]));
       /*
  set("objects",([
	  __DIR__"npc/yao":1,
	  ]));*/
   set("valid_startroom", 1);
   set("outdoors","huashan");
  setup();
 
}
