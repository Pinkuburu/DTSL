
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","工部");
  set ("long", @LONG
这里是“六部”之一的工部，负责国家的建设，水利，灾害等事务，平
时也是六部中比较繁忙的部门，进进出出的办事人员很多。
LONG);

  set("exits", ([ 
 "east":__DIR__"tianjie1",
       ]));
  set("valid_startroom", 1);
  setup();
 
}

