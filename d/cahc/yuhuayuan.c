
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","御花园");
  set ("long", @LONG
御花园用彩石铺路，古朴别致。园内甬路均以不同颜色的卵石精心
铺砌而成，组成九百余幅不同的图案，有人物、花卉、景物、戏剧、典
故等，沿路观赏，妙趣无穷。园中奇石罗布，佳木葱茏，其古柏藤萝，
皆数百年物，将花园点缀得情趣盎然。 

LONG);

  set("exits", ([ 
 "north":__DIR__"xuanwumen",
 "southup":__DIR__"yanjiadian",
 "west":__DIR__"jiashan",
 "east":"/d/job/liyuanjob/guanyuting",
        ]));
  set("objects",([
          "/d/cahc/npc/pinfei":1,
          "/d/cahc/npc/shinv":3,
          ]));
  set("outdoors","changan");
  
  set("valid_startroom", 1);
  setup();
 
}

