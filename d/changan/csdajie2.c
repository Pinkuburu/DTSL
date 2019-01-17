
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","长升大街");
  set ("long", @LONG
这是长升大街，南北连接长安城的长乐坊和升道坊。这里不再那么
静悄悄了，街上十分热闹，人来人往川流不息。东面有一家镖局。
西面有一个兵营。
LONG);

  set("exits", ([ 
 "north":__DIR__"csdajie3",
 "south":__DIR__"gmdajie1",
 "east":__DIR__"biaoju",
 "west":__DIR__"bingying",
       ]));
  set("objects",([
   __DIR__"npc/xiaofan":1,
   ]));
   
  set("outdoors","changan");
  
  set("valid_startroom", 1);
  setup();
 
}

