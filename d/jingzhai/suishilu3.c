
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",HIG"碎石路"NOR);
  set ("long", @LONG
这里是条碎石路。西边是慈航静斋的普善堂，东边是慈航静斋的练
武场，南边是间兵器室。
LONG);

  set("exits", ([ 

  "west":__DIR__"pushantang",
  "south":__DIR__"bingqishi",
  "east":__DIR__"lianwuchang",
      ]));
  /*set("objects",([
	  __DIR__"npc/bing":2,
	  ]));*/
  set("outdoors","jingzhai");
  set("valid_startroom", 1);
  setup();
 
}

