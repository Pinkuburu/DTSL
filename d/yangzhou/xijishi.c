
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","西集市");
  set ("long", @LONG
这里是扬州的五大集市之一西集市。这里也是扬州最热闹的地方之
一。每天有很多人在这里做生意，这里的买卖讲价的声音不绝，似乎可
以让人们暂时忘记战争带来的苦恼。
LONG);

  set("exits", ([ 
 "north":__DIR__"xidajie3",
 "south":__DIR__"yanju",
        ]));
  set("objects",([
   __DIR__"npc/xiaofan":1,
   __DIR__"npc/jumin":1,
   ]));
  set("outdoors","yangzhou");
  
  set("valid_startroom", 1);
  setup();
 
}

