
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","山路");
  set ("long", @LONG
这里是条山路。南边是秦岭。这里人迹罕至，几乎没有什么人。许
多人要路过这里，都是结伴而行。据说这里经常有强盗出没。
LONG);

  set("exits", ([ 
  "northeast":__DIR__"guanlu2",
  "northwest":__DIR__"luanshigang",
  "southup":__DIR__"shanlu2",
         ]));
set("outdoors","luoyang");
  set("valid_startroom", 1);
  setup();
 
}

