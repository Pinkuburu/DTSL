
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","后殿");
  set ("long", @LONG
这里是掖庭宫的后殿，两侧有不少屋宇楼阁，都是李世民的内眷们
居住的地方，殿内珠帘低垂，红烛高照，几个宫装少女和太监正在收拾
房间。
LONG);

  set("exits", ([ 
 "northdown":__DIR__"qingshilu1",
 "south":__DIR__"tiancedian",
 "eastdown":__DIR__"tongmingmen",
        ]));
    set("objects",([
        __DIR__"npc/shinv":1,
    ]));
  
  
  set("valid_startroom", 1);
  setup();
 
}

