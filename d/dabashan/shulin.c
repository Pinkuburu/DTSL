
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","树林");
  set ("long", @LONG
这里是大巴山的片树林。树木不是十分茂盛，衬托着大巴山险峻的
地形，别有一番景象。
LONG);

  set("exits", ([ 

   "northeast":__DIR__"shanlu2",
           ]));

 set("objects",([ "/d/clone/npc/beast/she":1,]));
set("outdoors","dabashan");
  
  set("valid_startroom", 1);
  setup();
 
}

