
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","长廊");
  set ("long", @LONG
这里是条长廊。长廊的墙壁上画着各种彩画，有风景、人物。一看
就是出自名家工匠之手。南边就是阴癸派教主的卧室了。近来阴癸派派
了很多门人潜伏于江湖各处，所以要用书信联络。有很多弟子从教主那
里领了联络书信匆匆走出。
LONG);
  set("exits",([
	  "west":__DIR__"liangting",
	  "south":__DIR__"woshi2",
	  ]));

  
  set("valid_startroom", 1);
  setup();
 
}

