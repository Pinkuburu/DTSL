
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",HIG"后殿"NOR);
  set ("long", @LONG
这里就是洛阳皇宫的后殿。一般皇上在临朝前都要到这里休息。但
是现在皇帝荒淫无度，所以这里也就没什么作用了。从这里可以到皇帝
的寝宫。
LONG);

  set("exits", ([ 
  
  "southeast":__DIR__"shijie3",
  "north":__DIR__"qingshilu3",
  "southwest":__DIR__"shijie2",
         ]));
 set("objects",([
   __DIR__"npc/guanbing":2,
   ]));
  
  set("valid_startroom", 1);
  setup();
 
}

