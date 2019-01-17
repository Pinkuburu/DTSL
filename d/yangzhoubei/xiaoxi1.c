
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","小溪");
  set ("long", @LONG
这里一个小溪。溪水清澈，从你的面前汩汩流过。你不时可以看到
有野兔等小动物在旁边喝水。
LONG);

  set("exits", ([ 
 "northeast":__DIR__"shanlu1",
 "south":__DIR__"shulin1",
        ]));
  set("objects",([
        __DIR__"npc/yetu":1
      ]));
  set("resource/water",1);
  set("outdoors","yangzhoubei");
  
  set("valid_startroom", 1);
  setup();
 
}

