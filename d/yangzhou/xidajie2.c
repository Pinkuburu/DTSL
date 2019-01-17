
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","西大街");
  set ("long", @LONG
这里是扬州城的西大街。东面不远处就是扬州的中心了。北面是扬
州的总管府。门口有几个官兵守卫在那里，眼神凌厉地注视着来往的行
人。南面是一家扬州著名的小吃店，里面传了阵阵香气，你添了添嘴，
不禁有些饿了。
LONG);

  set("exits", ([ 
 "east":__DIR__"xidajie3",
 "west":__DIR__"xidajie1",
 "north":__DIR__"zongguanfu",
 "south":__DIR__"xiaochidian",
"northwest":"/d/slwg/damen",
        ]));
  set("objects",([
    "/d/clone/npc/chenshoubei":1,
    ]));
  set("outdoors","yangzhou");
  
  set("valid_startroom", 1);
  setup();
 
}

