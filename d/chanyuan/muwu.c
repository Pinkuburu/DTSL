
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","木屋");
  set ("long", @LONG
这里是净念禅院的一个小木屋，是会客僧人的住处。在这里你可以
向会客僧人要些香烛等东西，不过要交些香火钱。这里的摆设朴素，有
很多上香的人在这里买香烛。
LONG);

  set("exits", ([ 
	  "southdown":__DIR__"shilu2",	
         ]));
  set("objects",([
    __DIR__"npc/huikeseng":1,
    ]));
  set("valid_startroom", 1);
  setup();
 
}

