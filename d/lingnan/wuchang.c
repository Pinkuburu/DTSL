
#include <ansi.h>

inherit ROOM;


void create ()
{
  set ("short","武场");
  set ("long", @LONG
这里是宋家堡的练武场。许多弟子就在这里练习武艺。几个弟子正
在这里努力地练习宋家刀法，只见刀光闪闪，武场顿时变得杀气腾腾。
东面是宋家堡的兵器室，南边是宋家堡弟子休息的地方。
LONG);

  set("exits", ([ 

   "west":__DIR__"liangting1",
   "east":__DIR__"bingqishi",
   "south":__DIR__"xiuxishi",
       ]));
  set("objects",([
	  __DIR__"npc/songlu":1,
	  __DIR__"npc/boy":2,
	  ]));

  set("valid_startroom", 1);
  set("outdoors","lingnan");
  setup();
 
}

