
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","北大街");
  set ("long", @LONG
这里是扬州城的北大街。北面是扬州的北门了。南边是扬州的北集
市，也是扬州最热闹的地方之一。东边是扬州著名的北城关帝庙。这里
行人也很多，战乱时还能如此繁华的城市，恐怕也只有扬州了。
LONG);

  set("exits", ([ 
 "northeast":__DIR__"beimen",
 "southwest":__DIR__"beijishi",
 "west":__DIR__"xiaolou",
        ]));
  
  set("objects",([
       "/d/clone/npc/dugu-sheng":1,
       ]));
  set("outdoors","yangzhou");
  
  set("valid_startroom", 1);
  setup();
 
}

