
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","势力篇");
  set ("long", @LONG
这里将介绍大唐中最为团结的地方：势力。在这里，你要与你同一
组织的人共奋斗，为了你们的经验和金钱努力！如果想更好的了解内容，
请使用 help banghui 来查看。一但加入了帮会，你也就卷入了血腥的
江湖之中，可不要随便对其他势力的人下 KILL 啊。
LONG);

  set("exits", ([ 
 "east":__DIR__"room1",
        ]));
  
set("no_fight",1);
set("no_exert",1);
  set("valid_startroom", 1);
  setup();
 
}

