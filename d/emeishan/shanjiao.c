
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","山脚");
  set ("long", @LONG
这里是峨眉山的山脚下。从这里可以看到峨眉山的秀丽景色。这里
有很多游人，都是为了一睹峨眉山的风光。
LONG);

  set("exits", ([ 
 "northup":__DIR__"xiaojing1",
 "westup":__DIR__"shanlu1",
 "eastdown":__DIR__"shanlu4",
       ]));
   set("outdoors","emeishan");
 set("valid_startroom", 1);
  setup();
 
}

