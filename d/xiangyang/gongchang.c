#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","工场");
  set ("long", @LONG
这里铁匠工会的工场，里面有一个很大的炼铁炉，一个强壮非常的
的打铁工正在挥舞着铁锤，旁边的兵器架上摆放着刚打造出来的还冒着
热气的各种兵器。
LONG);

  set("exits", ([ 
 "west":__DIR__"tiejianggh",
       ]));
  set("objects",([
	  "/d/job/tiejiangjob/tiejiang2":1,
	  ]));
  set("valid_startroom", 1);
  setup();
 
}

