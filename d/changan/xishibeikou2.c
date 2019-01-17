
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","西市北口");
  set ("long", @LONG
这里就是位于光明大街上的闻名长安的西市－利人市的北口，十字
路口向南，就能走到热闹非凡的西市。北面是一座古朴的寺院，一阵阵
僧人颂经的梵音，与一阵阵喧嚣的叫卖声相互搀杂，显得十分怪异。
LONG);

  set("exits", ([ 
 "north":__DIR__"wulousi",
 "south":__DIR__"xishidongjie1",
 "west":__DIR__"xishibeikou1",
 "eastup":__DIR__"gmqiao",
        ]));
  set("objects",([
         __DIR__"npc/xiaojie":1,
         ]));
  set("outdoors","changan");
  set("valid_startroom", 1);
  setup();
 
}

