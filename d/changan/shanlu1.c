
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","山路");
  set ("long", @LONG
这里是一条山路。这里是一条连绵的山脉的中部。这里的行人不是
很多，多是三三两两成群，看来是为了预防强盗。一阵风吹来，卷起阵
阵黄沙，一股苍凉之意油然而生。
LONG);

  set("exits", ([ 
"west":__DIR__"guanlu2",
"northeast":__DIR__"bianquemu",
"southeast":__DIR__"shanlu2",
        ]));
 set("outdoors","changan");
  
  set("valid_startroom", 1);
  setup();
 
}

