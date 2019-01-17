
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","和光大街");
  set ("long", @LONG
这是和光大街，南北连接长安城的光化门和和平坊。这里不再那么静
悄悄了，街上十分热闹，人来人往川流不息。西面有一家药店，东面是长
安有名的酒楼--长安楼。
LONG);

  set("exits", ([ 
 "north":__DIR__"hgdajie3",
 "south":__DIR__"gmdajie7",
 "east":__DIR__"changanlou",
 "west":__DIR__"huichuntang",
       ]));
  set("objects",([
         __DIR__"npc/haoke":1,
         __DIR__"npc/baixing":1,
         ]));
  set("outdoors","changan");
  
  set("valid_startroom", 1);
  setup();
 
}

