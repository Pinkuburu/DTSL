
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","广运门");
  set ("long", @LONG
这里是掖庭宫的南大门，隋文帝时，杨广在此居住，后来策划并发
动了政变，弑兄纂位，后来李阀攻陷长安，掖庭宫就成了李世民在长安
的居处。天策府就设在里面，有不少带刀侍卫认真的把守在门前。
LONG);

  set("exits", ([ 
 "north":__DIR__"chengqingmen",
 "south":__DIR__"hggc1",
        ]));

  set("objects",([
          "/d/changan/npc/shiwei":2,
        ]));
  set("outdoors","changan");
  set("valid_startroom", 1);
  setup();
 
}

