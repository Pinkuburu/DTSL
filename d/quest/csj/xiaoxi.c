
inherit ROOM;
#include <ansi.h>

void create()
{
	set("short","小溪");
	set("long", @LONG
这是一条小溪边，这里风景秀丽，地势隐蔽，看起来似乎平时没有
人来这里。这里非常寂静，除了几声飞鸟的鸣叫，没有半点声息。看来
这里离扬州已经很远了。
LONG);
        set("exits",([          
          "down":__DIR__"migong10",
          ]));
        set("objects",([
         __DIR__"npc/fu":1,
        ]));
	setup();      
}
