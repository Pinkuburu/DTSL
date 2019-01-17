
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","仙掌崖");
  set ("long", @LONG
每逢晴朗的早晨，掌印如镀赤金，巍然矗立，光彩壮丽，观赏者无
不叹为观止。登山途中在苍龙岭，五云峰等处也可近观仙掌，但效果不
如远观。
LONG);

  set("exits", ([ 
 "southeast":__DIR__"yanggongta",
 "northwest":__DIR__"wushangdong",
       ]));
       /*
  set("objects",([
	  __DIR__"npc/yao":1,
	  ]));*/
  set("valid_startroom", 1);
   set("outdoors","huashan");
  setup();
 
}
