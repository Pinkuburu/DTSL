
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",HIG"石阶"NOR);
  set ("long", @LONG
这里是石阶。再往上走，就可以到皇宫后殿和寝宫了。
LONG);

  set("exits", ([ 
  
  "northeast":__DIR__"houdian",
  "south":__DIR__"guanhuayuan",
         ]));

  set("objects",([
   __DIR__"npc/gongnv1":1,
   ]));
  set("valid_startroom", 1);
  setup();
 
}

