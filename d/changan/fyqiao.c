
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","飞云桥");
  set ("long", @LONG
这是一座白色的石桥，跨越在南北流向的永安渠之上，桥下舟楫往
来，桥上行以车马不绝，四周尽是巨宅豪户，站在桥上向远处看去，能
够看到北面的光明桥和南面的跃马桥。
LONG);

  set("exits", ([ 
  "westdown":__DIR__"xishidongjie2",
  "eastdown":__DIR__"xishidongkou1",
        ]));
  set("objects",([
   __DIR__"npc/gongzi":1,
   ]));
   
  set("outdoors","changan");
  set("valid_startroom", 1);
  setup();
 
}

