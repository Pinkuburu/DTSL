
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","驿站");
  set ("long", @LONG
这里是提供更换马匹，出租马匹服务的地方。本来是供给来洛阳的
游客所用，现在则成了官府征用的消息驿站。
LONG);

  set("exits", ([ 
      "east":__DIR__"changxiajie2",
  ]));
  set("valid_startroom", 1);
  setup();
 
}

