
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","兵营");
  set ("long", @LONG
这里是襄阳的兵营，平时这里有很多的士兵，老百姓更是不敢来这
里。只见几个官兵正在兵营的门口打着盹。地上横七竖八地放着各种兵
器，有几匹马正在兵营周围走动，因为没有人仔细喂养，已经瘦得不成
样子了。
LONG);

  set("exits", ([ 
 "west":__DIR__"nandajie4",
        ]));
  set("outdoors","xiangyang");
 set("valid_startroom", 1);
  setup();
 
}

