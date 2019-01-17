
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","官路");
  set ("long", @LONG
你走在一条青石大道上，人来人往非常繁忙，不时有人骑着马匆匆
而过。东边通向长安城。路两旁青山挺拔。不时从旁边的草地里跳出几
只兔子，然后被行人吓到草丛里面消失了。
LONG);

  set("exits", ([ 
 "east":__DIR__"guandao2",
 "west":__DIR__"guandao4",
        ]));
  set("outdoors","changan");
  
  set("valid_startroom", 1);
  setup();
 
}

