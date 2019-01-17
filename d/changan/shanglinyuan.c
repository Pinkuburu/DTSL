
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","上林苑");
  set ("long", @LONG
这里是长安的城内有名的妓院，据说在国内都是非常出了名。上林
苑之所以名闻全国，确有其独特的风貌，不像六福赌馆和明堂窝般那样
用大量的彩色琉璃的三采砖瓦作装饰，而是追求一种高贵淡雅、充满书
卷气味的装饰。入门后的主建筑物最具代表性，大片的灰砖墙，屋顶是
黑色琉璃瓦绿色的剪边，檐下是青绿的采画，支柱和隔扇栏杆都不施采
绘而露出木材原色，柱上楹联亦以硬木制作，温文尔雅，难怪诗人墨客
颂声不绝。
LONG);

  set("exits", ([ 
 "east":__DIR__"yadajie3",
        ]));
  set("objects",([
	  __DIR__"npc/xiaoxiang":1,
	  ]));
  set("valid_startroom", 1);
  setup();
 
}

