
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",HIG"练武场"NOR);
  set ("long", @LONG
这里是慈航静斋的练武场。慈航静斋的习武以普善为本。有几名弟
子在这里练习武艺，动作幽雅，身形敏捷。
LONG);

  set("exits", ([ 

  "west":__DIR__"suishilu3",
    ]));
  /*set("objects",([
	  __DIR__"npc/bing":2,
	  ]));*/
  set("outdoors","jingzhai");
  set("valid_startroom", 1);
  setup();
 
}

