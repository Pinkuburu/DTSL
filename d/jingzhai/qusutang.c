
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",HIW"去俗堂"NOR);
  set ("long", @LONG
这里是慈航静斋的去俗堂。此堂的含义是慈航静斋的弟子看到去俗
堂三个字，就要时刻谨记去俗二字。这里庄严肃穆，你心中的杂念也少
了许多。
LONG);

  set("exits", ([ 

  "west":__DIR__"wuwangdian",
  "east":__DIR__"wuyutang",
  "south":__DIR__"wutantang",
  "north":__DIR__"wuchentang",
       ]));
  /*set("objects",([
	  __DIR__"npc/bing":2,
	  ]));*/
  
  set("valid_startroom", 1);
  setup();
 
}

