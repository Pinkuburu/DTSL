
#include <room.h>

inherit ROOM;
void create()
{
	set("short", "兵器铺");
	set("long", @LONG
这里是石龙武馆的兵器铺，想使用兵器的弟子可以到这里来买兵器。
这里的兵器种类繁多，应有尽有。不过这里的兵器威力不大，只能用做练
武之用。
LONG
);


	set("exits", ([
		  "east":__DIR__"zoulang1",
	]));
	set("objects",([
	    __DIR__"npc/tiejiang":1,
	    ]));
       set("no_fight",1);
    
	setup();
}

