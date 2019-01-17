
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","西大街");
  set ("long", @LONG
这里是襄阳的西大街。西面就是襄阳的西门了。由于战乱，所以很
少有老百姓来这里。北边是襄阳的盐局，和扬州的盐局保持着密切的联
系，经常有武林中人护着盐车从这里走过。南边是一个兵营，有几个官
兵正在兵营的门口打盹。
LONG);

  set("exits", ([ 
 "east":__DIR__"xidajie2",
 "south":__DIR__"bingying1",
 "west":__DIR__"ximen",
 "north":__DIR__"yanju",
        ]));
  set("outdoors","xiangyang");
  
  set("valid_startroom", 1);
  setup();
 
}

