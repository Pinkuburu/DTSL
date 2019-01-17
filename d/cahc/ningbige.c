
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","凝碧阁");
  set ("long", @LONG
穿过蜘蜒于竹林的小径，眼前豁然开朗，东御池之北，罗植各种花
卉草木，凝碧的地水映照下，凝碧阁座落其间，台殿亭阁，与四周的环
境融浑为一。这里住的是李渊的宠妃张捷妤。 
LONG);

  set("exits", ([ 
 "south":__DIR__"dongyuchi",
        ]));
  set("objects",([
           __DIR__"npc/zhangjieyu":1,
        ]));
  set("valid_startroom", 1);
  setup();
 
}

