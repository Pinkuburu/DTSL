
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","白石广场");
  set ("long", @LONG
白石广场正中处供奉了一座文殊菩萨的铜像，骑在金毛狮背，高达
两丈许，龛旁还有药师、释迦和弥陀等三世佛。彩塑金饰，颇有气魄，
但亦令人觉得有点不合一般寺院惯例。
LONG);

  set("exits", ([ 
	  "eastup":__DIR__"shijie1",
	  "west":__DIR__"shilu2",
          "southdown":__DIR__"zhulin",
         ]));

  set("outdoors","chanyuan");
  set("valid_startroom", 1);
  setup();
 
}

