
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","农舍");
  set ("long", @LONG
这里是一间由土坯砌成的小屋，屋内除了一张床，一套桌椅外再没
有什么摆设了。门上贴着一个门神。
LONG);

  set("exits", ([ 
 "west":__DIR__"nongtian1",
       ]));
   set("objects",([
      __DIR__"npc/nongfu":1,
      ]));
  set("valid_startroom", 1);
  setup();
 
}

