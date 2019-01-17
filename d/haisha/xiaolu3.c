
#include <ansi.h>
inherit ROOM;
void create ()
{
  set ("short","小路");
  set ("long", @LONG
这里是渔村的内的一条小路。北边不时传来呻吟的声音，似乎有人
再受刑。南边却不时传来欢呼的声音。
LONG);

  set("exits", ([ 

  "west":__DIR__"xiaolu2",
  "east":__DIR__"haitan",
  "northeast":__DIR__"zhifatang",
  "south":__DIR__"fenzangpeng",
       ]));
  set("outdoors","haisha");
  
  set("valid_startroom", 1);
  setup();
 
}

