
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","长升大街");
  set ("long", @LONG
这是长升大街，南北连接长安城的长乐坊和升道坊。大街上十分热
闹，人来人往川流不息。从这里向北，可以到达北面的一条东西方向主
路－－通远大街。西面是个驿站，东面有家武馆。
LONG);

  set("exits", ([ 
 "north":__DIR__"tydajie8",
 "south":__DIR__"csdajie2",
 "west":__DIR__"yizhan",
 "east":__DIR__"wuguan",
        ]));
 
  set("outdoors","changan");
  set("valid_startroom", 1);
  setup();
 
}

