
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","大广场");
  set ("long", @LONG
这里是天策殿前的一个广场，四周种满了大理的名茶花，中间一 
条白玉大道直通天策殿，大道两旁站着一排整齐严肃的玄甲军，显得 
格外的庄严肃穆。

LONG);

  set("exits", ([ 
 "northup":__DIR__"tiancedian",
 "southup":__DIR__"chengqingdian",
 "east":"/d/clone/room/orgsaferoom/lifa/baihutang",
 "west":__DIR__"woshi",
        ]));
  set("outdoors","changan");
  
  set("valid_startroom", 1);
  setup();
 
}

