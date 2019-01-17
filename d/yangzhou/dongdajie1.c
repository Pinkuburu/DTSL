
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","东大街");
  set ("long", @LONG
这里是扬州城的东大街。西面是扬州的瘦西湖边。这里的行人也是
很多，丝毫不逊色于其他地方。这里有扬州最出名的神算子，他的生意
非常好，平时有很多来这里算命的人。南面有一家兵器店，从这里就可
以听到里面乒乓打造兵器的声音。
LONG);

  set("exits", ([ 
 "northeast":__DIR__"dongdajie2",
 "northwest":__DIR__"donghudi3",
  "south":__DIR__"bingqidian",
        ]));
  set("objects",([
     "/d/clone/npc/suanming":1,
     ]));
  set("outdoors","yangzhou");
  
  set("valid_startroom", 1);
  setup();
 
}

