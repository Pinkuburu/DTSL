
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",HIG"碎石路"NOR);
  set ("long", @LONG
这里是条碎石路。南边通往慈航静斋的后清殿。北边是慈航静斋的
普善堂。不时有慈航静斋的弟子和你擦肩而过。
LONG);

  set("exits", ([ 

  "north":__DIR__"pushantang",
  "south":__DIR__"houqingdian",
  "east":__DIR__"chufang",
      ]));
  /*set("objects",([
	  __DIR__"npc/bing":2,
	  ]));*/
  set("outdoors","jingzhai");
  set("valid_startroom", 1);
  setup();
 
}

