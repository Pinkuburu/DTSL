
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",HIC"开合桥"NOR);
  set ("long", @long
开合桥乃是洛阳四大名桥之一，它的设计精巧别致，往往令第一次
来洛阳的游客大吃一惊。
long);

  set("exits", ([ 
  

  "north":__DIR__"xiangwangjie2",
  "southup":__DIR__"kaiheqiao2",
         ]));

  set("outdoors","luoyang");
  set("valid_startroom", 1);
  setup();
 
}

