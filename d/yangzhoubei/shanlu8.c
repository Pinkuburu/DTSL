
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","山路");
  set ("long", @LONG
这里是条山路。这里的天气有些冷了。据说这里也有盗贼出没，你
不禁小心起来。远处隐隐约约可以听到哭喊打骂的声音，似乎又是官兵
在洗劫平民百姓。
LONG);

  set("exits", ([ 
 "east":__DIR__"shanlu9",
 "southwest":__DIR__"shanlu7",
        ]));
  set("outdoors","yangzhoubei");
  
  set("valid_startroom", 1);
  setup();
 
}

