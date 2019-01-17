
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","官路");
  set ("long", @LONG
这里是一条官路。再往东走就是扬州了。往西走就是安徽的境地了。
这里只有稀稀落落的几个行人。
LONG);

  set("exits", ([ 
 "east":__DIR__"guanlu1",
 "northwest":__DIR__"xiaolu1",
        ]));
  set("objects",([
   __DIR__"npc/youke":2,
   ]));
  set("outdoors","yangzhou");
  
  set("valid_startroom", 1);
  setup();
 
}

