
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",GRN"台地"NOR);
  set ("long", @LONG
这里是小楼门前的台地。对着入口处的两道梁柱挂有一联，写在木
牌上，“朝宜调琴，暮宜鼓瑟；旧雨适至，新雨初来。”字体飘逸出尘，
苍劲有力。此堂是四面厅的建筑形式，通过四面花木鬲窗，把后方植物
披盖的危崖峭壁，周围的婆娑柔篁，隐隐透入厅内，更显得其陈设的红
木家具浑厚无华，闲适自然。屋角处有道楠木造的梯阶，通往上层。
LONG);

  set("exits", ([ 

	  "west":__DIR__"xiaolu6",
	  "up":__DIR__"louwu1",
  ]));

  
  set("valid_startroom", 1);
  setup();
 
}

