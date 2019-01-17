
#include <ansi.h>

inherit ROOM;


void create ()
{
  set ("short","西廊");
  set ("long", @LONG
这里是西廊。北面是宋家堡的堡主宋缺的书房，西南有一座小桥。
长廊的墙壁上刻画着一些精美的壁画，种类繁多，有山水、人物等。均
是优秀工匠所做。不时有一些宋家堡弟子从你的身旁匆匆走过。
LONG);

  set("exits", ([ 

  "east":__DIR__"xilang1",
  "north":__DIR__"shufang",
  "southwest":__DIR__"xiaoqiao3",
       ]));

  set("valid_startroom", 1);
  set("outdoors","lingnan");
  setup();
 
}

