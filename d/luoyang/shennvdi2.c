
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","神女堤");
  set ("long", @long
这里北连开合桥，南通长夏大街，西到立秋门，正是洛阳一个重要
的交通要道。
long);

  set("exits", ([ 
  
  	"north":__DIR__"kaiheqiao3",
  	"west":__DIR__"shennvdi1",
  	"east":__DIR__"shennvdi3",
  	"south":__DIR__"changxiajie1",
  
  ]));

  set("outdoors","luoyang");
  set("valid_startroom", 1);
  setup();
 
}

