
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","树林");
  set ("long", @LONG
这里是一片树林。这里的树木茂盛，遮住了阳光，所以看起来这里
有些阴暗。这里的人际罕至，只有几只野兔经常从你的身旁跑过。
LONG);

  set("exits", ([ 
 "west":__DIR__"shanlu6",
       ]));
 set("objects",([ "/d/clone/npc/beast/xiong":1,]));
   set("valid_startroom", 1);
   set("no_select",1);
   set("outdoors","huashan");
  setup();
 
}
