
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","山路");
  set ("long", @LONG
这里是条山路。南边就是长江的边了，这里可以听到江水的声音。
不时有大队的官兵从你的身旁走过，吓得路上的百姓都朝两边闪去。
LONG);

  set("exits", ([ 

  "northeast":__DIR__"shanlu2",
  "south":__DIR__"caodi2",
       ]));
  
set("outdoors","hefei");
  
  set("valid_startroom", 1);
  setup();
 
}

