
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","小饭馆");
  set ("long", @LONG
这里是一个小饭馆。由于洛阳城近来人突然增多，所以生意一直很
好。店小二忙来忙去跑个不停。只见几个江湖人士正在那里高谈阔论，
旁边还放这两三个酒坛子。掌柜正在那里仔细的算帐，算盘打得劈啪地
响。
LONG);

  set("exits", ([ 
      "west":__DIR__"qinglongjie1",
  ]));
  set("objects",([
      __DIR__"npc/xiaoer3":1,
  ]));
  set("valid_startroom", 1);
  setup();
 
}

