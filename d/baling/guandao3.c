
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","青石官道");
  set ("long", @LONG
这里是条官路。南边是巴陵的北门。这里的行人来来往往，有些热
闹。南来北往的有很多车马，一派热闹的景象。不时有飞驰快马从你身
边跑过，吓得路上的百姓都朝两边闪去。
LONG);

  set("exits", ([ 

  "south":__DIR__"guandao2",
  "north":__DIR__"guandao4",
  "northwest":__DIR__"yingmen",
       ]));

set("outdoors","baling");
  
  set("valid_startroom", 1);
  setup();
 
}

