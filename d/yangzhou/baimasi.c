
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","白马寺");
  set ("long", @LONG
这里是扬州城的白马寺。由于连年的战乱，这里上香拜佛的人不是
很多了，只有几个僧人在这里打理寺中的事物。佛祖虽然法力无边，但
现在却无法解救世人的痛苦。
LONG);

  set("exits", ([ 
 "north":__DIR__"xidajie1",
        ]));
  set("objects",([
          "/d/job/jj/heshang2":1,
          __DIR__"npc/shami":1,
          ]));
set("no_fight",1);set("no_exert",1);
  set("valid_startroom", 1);
  setup();
 
}

