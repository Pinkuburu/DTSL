
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","山路");
  set ("long", @LONG
人在华山之中，仰头望去，华山的山峰耸立入云，远处的玉女峰更
是遥触天边。这里不时有游人走过，对着华山的美丽景色赞不绝口。华
山自古就是名川大山之一，就是有关华山的神话也是很多，据说在华山
还有很多与世隔绝的圣人。
LONG);

  set("exits", ([ 
 "southup":__DIR__"yuquanyuan",
            "northwest":"/d/taiyuan/road8a",
       ]));
  set("objects",([
	  __DIR__"npc/yao":1,
	  ]));
  set("no_select",1);
   set("valid_startroom", 1);
   set("outdoors","huashan");
  setup();
 
}
