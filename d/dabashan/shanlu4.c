
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short","山路");
  set ("long", @LONG
这里是一条山路。东边是一个山脊。四周怪石嶙峋，地形看起来非
常险要。西边有一个山坡，看起来是下山的路。
LONG);

  set("exits", ([ 

   "east":__DIR__"shanji1",
   "westdown":__DIR__"shanpo",
         ]));

set("outdoors","dabashan");
  
  set("valid_startroom", 1);
  setup();
 
}

