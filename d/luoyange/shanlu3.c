
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","山路");
  set ("long", @LONG
这里是一条向上去的山路。西面有一座吊桥，看来是上山的必经之
关了。大概这里就是飞马牧场的入口了。
LONG);

  set("exits", ([ 
  "southeast":__DIR__"caoyuan",
  "northwest":"/d/feima-muchang/bridge",
        ]));
 set("outdoors","luoyang");
  set("valid_startroom", 1);
  setup();
 
}

