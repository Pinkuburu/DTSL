
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","安化大街");
  set ("long", @LONG
这是安化大街，南北连接长安城的安化门和芳林门。这条街是长安
的南北向主要大街，长安皇城就在安化北街的东面。街上十分热闹，人
来人往川流不息。
LONG);

  set("exits", ([ 
 "north":__DIR__"gmdajie5",
 "south":__DIR__"ahdajie2",
 "east":__DIR__"jiangjunfu",
       ]));
  set("outdoors","changan");
  set("valid_startroom", 1);
  setup();
 
}

