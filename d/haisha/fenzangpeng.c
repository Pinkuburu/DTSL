
#include <ansi.h>
inherit ROOM;
void create ()
{
  set ("short","分赃棚");
  set ("long", @LONG
这里是海沙帮的分赃棚。海沙帮每作成一件生意，都聚集在这里分
赃。这里通常是欢呼连天，但也有分赃不均，挑斗生事的时候。
LONG);

 set("no_fight",1);
set("no_exert",1);
  set("exits", ([ 

  "north":__DIR__"xiaolu3",
       ]));
  /*
  set("objects",([
    "/d/job/haishajob/cai":1,
    ]));
  */
  set("valid_startroom", 1);
  setup();
 
}

