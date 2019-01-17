
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","东市北口");
  set ("long", @LONG
这是一个在光明大街上的丁字路口，路南一条小街通向长安城闻名
的东市－－都会市。那里似乎是长安城最热闹的地方了，因为人还没到，
那喧嚣的声音已经传了过来。
LONG);

  set("exits", ([ 
 "south":__DIR__"dongshidongjie1",
 "east":__DIR__"gmdajie1",
 "west":__DIR__"dongshibeikou2",
        ]));
  set("objects",([
   __DIR__"npc/youke":1,
   __DIR__"npc/xiaofan":1,
   ]));
   
  set("outdoors","changan");
  
  set("valid_startroom", 1);
  setup();
 
}

