
#include <ansi.h>

inherit ROOM;


void create ()
{
  set ("short","大路");
  set ("long", @LONG
这里是个宽敞大路。这里已经可以清晰的看到扬州的城门了。扬州
自古就是繁华地带，在这里已经可以听到城内热闹的声音了。
LONG);

  set("exits", ([ 

  "southeast":__DIR__"dalu4",
  "west":__DIR__"dalu2",
  
         ]));

  set("valid_startroom", 1);
  set("outdoors","jiujiang");
  setup();
 
}

