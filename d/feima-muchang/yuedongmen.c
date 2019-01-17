
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",HIG"月洞门"NOR);
  set ("long", @LONG
这里是一个月洞门。东面据说是飞马牧场的禁地，没有场主的允许，
是没有人敢去那里的。这里静悄悄的，没有丝毫的声音。
LONG);

  set("exits", ([ 
	  "east":__DIR__"huayuan2",
	  "west":__DIR__"yuanlin",
    ]));

  set("outdoors","feima");
  set("valid_startroom", 1);
  setup();
 
}

