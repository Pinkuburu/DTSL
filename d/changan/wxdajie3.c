
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","望仙大街");
  set ("long", @LONG
这是望仙大街，南北贯通长安城。大街上十分热闹，人来人往川流
不息。东面似乎是一家书院，因为有琅琅的读书声从那里传来。
LONG);

  set("exits", ([ 
 "north":__DIR__"tydajie7",
 "south":__DIR__"wxdajie2",
 "east":__DIR__"zlshuyuan",
        ]));
  set("objects",([
   __DIR__"npc/baixing":1,
   __DIR__"npc/youke":1,
   ]));
   
  set("outdoors","changan");
  
  set("valid_startroom", 1);
  setup();
 
}

