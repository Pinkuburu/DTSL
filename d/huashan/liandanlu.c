
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","炼丹炉");
  set ("long", @LONG
炼丹炉相传为太上老君炼制金丹的地方，故峰又称丹峰。旧有庙宇
建筑，但规模较小，庙前设有铁制丹炉一座，氢《三才图会》载，“炉
径丈余，高可六尺。”《玄怪录》中所载的浪子杜子春丹房奇遇的神话
故事即发生于此。
LONG);

  set("exits", ([ 
 "northdown":__DIR__"julingzu",
 "southeast":__DIR__"yangtianchi",
 "east":__DIR__"pubu",
       ]));
  /*set("objects",([
	  __DIR__"npc/yao":1,
	  ]));*/
   set("valid_startroom", 1);
   set("outdoors","huashan");
  setup();
 
}
