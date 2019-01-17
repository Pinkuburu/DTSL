
#include <ansi.h>

inherit ROOM;


void create ()
{
  set ("short","小桥");
  set ("long", @LONG
这里是个小桥。桥下流水哗哗声响，不觉的心神舒畅。有几个宋家
堡的弟子正在桥上休息，悠闲地看着桥下水中的游鱼。不时有几名弟子
从你的身旁走过。
LONG);

  set("exits", ([ 

  "east":__DIR__"huayuan1",
  "southwest":__DIR__"xiaolu",
      ]));

  set("valid_startroom", 1);
  set("outdoors","lingnan");
  setup();
 
}

