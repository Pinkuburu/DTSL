
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","都水监");
  set ("long", @LONG
都水监是朝廷设立的中央机构，专门城市水路交通。河道，石桥，
码头等都在管辖范围内。
LONG);

  set("exits", ([ 
 "west":__DIR__"tianjie2",
         ]));
    set("valid_startroom", 1);
  setup();
 
}

