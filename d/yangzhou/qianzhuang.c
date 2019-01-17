
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","钱庄");
  set ("long", @LONG
这里是扬州城的钱庄，这家钱庄在扬州有悠久的历史，所以信誉一
直很好。据说钱庄老板和扬州的官府还有关系，所以虽然是战乱年代，
但这里目前还平安无事，以至有很多人来这里存钱。
LONG);

  set("exits", ([ 
 "west":__DIR__"nandajie3",
        ]));
  set("objects",([
	  __DIR__"npc/ouyang":1,
	  ]));
  set("no_fight", 1);
  set("valid_startroom", 1);
  setup();
 
}

