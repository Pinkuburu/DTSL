
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","海滨");
  set ("long", @LONG
这里是海滨。南边是茫茫的大海。岸边停着几艘渔船。远处有一个
小渔村，看起来有些荒凉，看来很快就要灭绝人迹了。
LONG);

  set("exits", ([ 
 "southeast":__DIR__"haibin7",
 "west":__DIR__"haibin5",
        ]));
  set("outdoors","yangzhoubei");
  
  set("valid_startroom", 1);
  setup();
 
}

