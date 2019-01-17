
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",HIG"走廊"NOR);
  set ("long", @LONG
这里是一条走廊。东边就是慈航静斋的静心殿了。从这里可以听到
诵经的声音。北边是苦心房、诵经房，南边是慈航静斋传授武艺的修罗
院。
LONG);

  set("exits", ([ 

  "east":__DIR__"jingxindian",
  "north":__DIR__"kuxinfang",
  "northwest":__DIR__"songjingfang",
  "southwest":__DIR__"xiuluoyuan",
       ]));
  /*set("objects",([
	  __DIR__"npc/bing":2,
	  ]));*/

  
  set("valid_startroom", 1);
  setup();
 
}

