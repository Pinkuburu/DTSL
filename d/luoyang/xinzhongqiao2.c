
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",HIC"新中桥"NOR);
  set ("long", @long
这座桥叫新中桥，横跨洛水，连接南北，只看此桥的规模，便具体
而微地说明了杨广当年如何劳民伤财。
long);

  set("exits", ([ 
  

  "northdown":__DIR__"xinzhongqiao1",
  "southdown":__DIR__"xinzhongqiao3",
         ]));
   set("objects",([
          "/d/yinkui/npc/zhengshi-ru":1,
          ]));

  set("outdoors","luoyang");
  set("valid_startroom", 1);
  setup();
 
}

