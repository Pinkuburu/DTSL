
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",HIR"正殿"NOR);
  set ("long", @LONG
这里是阴癸派的议事正殿。阴癸派的教主平时就在这里处理教中的
事物。正中是一张大椅子，两边放着一排椅子，背面的墙上画着一个大
大的火炬，在烛光的照耀下诡异无比。这里一派庄严的气氛，每个到这
里的人连大气也不敢出一声。
LONG);
  set("exits",([
	  "south":__DIR__"qingshilu2",
	  "north":__DIR__"houdian",
	  ]));

  
  set("valid_startroom", 1);
  setup();
 
}

