
#include <ansi.h>

inherit ROOM;


void create ()
{
  set ("short","东廊");
  set ("long", @LONG
这里是东廊。北面有一条青石路。长廊的墙壁上刻画着一些精美的
壁画，种类繁多，有山水、人物等。均是优秀工匠所做。不时有一些宋
家堡弟子从你的身旁匆匆走过。
LONG);

  set("exits", ([ 

  "west":__DIR__"donglang2",
  "north":__DIR__"qingshilu1",
       ]));

  set("valid_startroom", 1);
  set("outdoors","lingnan");
  setup();
 
}

