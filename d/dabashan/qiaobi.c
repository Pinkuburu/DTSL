
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","峭壁");
  set ("long", @LONG
这里是大巴山的一个峭壁。下面是万丈深渊，你向下望了望，腿不
觉的有写发软。
LONG);

  set("exits", ([ 

   "southeast":__DIR__"caishichang",
       ]));

set("outdoors","dabashan");
  
  set("valid_startroom", 1);
  setup();
 
}

