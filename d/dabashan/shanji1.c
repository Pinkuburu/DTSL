
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","山脊");
  set ("long", @LONG
这里是大巴山的山脊。你向下望去，只见都是陡峭的山崖。东边是
一条下山的路。这里的道路非常险峻，你不禁小心起来。
LONG);

  set("exits", ([ 

   "eastdown":__DIR__"shanjiao",
   "west":__DIR__"shanlu4",
   "northup":__DIR__"shanlu1",
   "south":__DIR__"shanlu2",
       ]));

set("outdoors","dabashan");
  
  set("valid_startroom", 1);
  setup();
 
}

