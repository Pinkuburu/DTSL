
#include <ansi.h>

inherit ROOM;


void create ()
{
  set ("short","凉亭");
  set ("long", @LONG
这里是座凉亭。凉亭的柱子上画了很多精美的壁画，均是出自优秀
的工匠之手。东边就是宋智的卧室了。有几个丫鬟在这里出出入入。
LONG);

  set("exits", ([ 

  "east":__DIR__"woshi2",
  "south":__DIR__"qingshilu2",
      ]));

  set("valid_startroom", 1);
  set("outdoors","lingnan");
  setup();
 
}

