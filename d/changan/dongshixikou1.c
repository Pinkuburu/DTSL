
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","东市西口");
  set ("long", @LONG
这是一个在望仙大街上的丁字路口，路东一条小街通向长安城闻名
的东市－－都会市。那里似乎是长安城最热闹的地方了，因为人还没到，
那喧嚣的声音已经传了过来。
LONG);

  set("exits", ([ 
 "south":__DIR__"dongshixikou2",
 "north":__DIR__"gmdajie2",
 "east":__DIR__"dongshixijie2",
        ]));
  set("outdoors","changan");
  
  set("valid_startroom", 1);
  setup();
 
}

