
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","卧房");
  set ("long", @long
这里是寻花问柳之士最垂涎之处了，不过不是每个人都能在这里过
夜的，也要打动那些歌妓的心才成。
long);

  set("exits", ([ 
 "east":__DIR__"2chuancang2",
 
        ]));
  set("objects",([
  	"/d/clone/npc/jinv":1,
  ]));
  set("sleep_room",1); 
  set("no_fight",1);
  set("valid_startroom", 1);
  setup();
 
}
