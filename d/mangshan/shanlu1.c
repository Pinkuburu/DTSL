
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","山路");
  set ("long", @LONG
这里是条山路，北面就是邙山了，南面就是东都洛阳。四周树木茂
盛，远处秀丽的风景映入眼帘，四周四周丛林密布，鲜花绿草若隐若现，
不时有鸟儿从你的头上飞过。
LONG);

  set("exits", ([ 

  "west":"/d/luoyang/tulu2",
 "northeast":__DIR__"shanlu2",
         ]));

  set("valid_startroom", 1);
  setup();
 
}

