
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","承恩殿");
  set ("long", @LONG
这里是东宫的后殿，两侧有不少屋宇楼阁，都是李建成的内眷们居
住的地方，殿内珠帘低垂，红烛高照，几个宫装少女和太监正在收拾房
间。
LONG);

  set("exits", ([ 
 "northdown":__DIR__"qingshilu3",
 "south":__DIR__"guangtiandian",
 "westdown":__DIR__"tongxunmen",
    ]));
    set("objects",([
         __DIR__"npc/shinv":1,
    ]));
  
  
  set("valid_startroom", 1);
  setup();
 
 
}

