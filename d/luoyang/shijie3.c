
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",HIG"石阶"NOR);
  set ("long", @LONG
这里是石阶。再往上走，就可以到皇宫后殿和寝宫了。
LONG);

  set("exits", ([ 
  
  "northwest":__DIR__"houdian",
  "south":__DIR__"yushanfang",
         ]));

  
  set("valid_startroom", 1);
  setup();
 
}

