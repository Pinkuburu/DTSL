
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","落雁峰");
  set ("long", @LONG
落雁峰是华山最高主峰，也是五岳最高峰，古人尊称它是“华山元
首”。登上南峰绝顶，顿感天近咫尺，星斗可摘。举目环视，但见群山
起伏，苍苍莽莽，黄河渭水如丝如缕，漠漠平原如帛如绵，尽收眼底。
使人真正领略华山高峻雄伟的博大气势，享受如临天界、如履浮云的神
奇情趣。
LONG);

  set("exits", ([ 
 "northdown":__DIR__"yangtianchi",
        ]));
  /*set("objects",([
	  __DIR__"npc/yao":1,
	  ]));*/
   set("valid_startroom", 1);
   set("outdoors","huashan");
  setup();
 
}
