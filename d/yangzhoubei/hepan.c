
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","河畔");
  set ("long", @LONG
这里是一条小河的河畔，由于长时间受到河水的滋润，旁边的植物
长的相当茂盛。河水清澈，景色宜人。
LONG);

  set("exits", ([ 
 "south":__DIR__"xiaolu4",
        ]));
  set("objects",([
    __DIR__"npc/yetu":2,
    ]));
  set("outdoors","yangzhoubei");
  
  set("valid_startroom", 1);
  setup();
 
}

