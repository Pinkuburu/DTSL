
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","洛阳土坊");
  set ("long", @LONG
这里是洛阳的闹市。北面是水坊桥。再往南走，就是白虎门了。这
里可以听到南边热闹的声音。
LONG);

  set("exits", ([ 
  
	  "west":__DIR__"dangpu",
  "northup":__DIR__"baihuqiao",
  "southeast":__DIR__"baihumen",

         ]));

  set("outdoors","luoyang");
  set("valid_startroom", 1);
  setup();
 
}

