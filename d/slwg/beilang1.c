
#include <room.h>

inherit ROOM;
void create()
{
	set("short", "北廊");
	set("long", @LONG
这里是石龙武馆的北厢廊。继续往北边走，就可以到石龙的书房和
卧室了。南边是武馆的正厅。厢廊的两旁是不大不小的荷花池，里面荷
花盛开，非常漂亮。
LONG
);


	set("exits", ([
		"north" :__DIR__"beilang2",
                "south":__DIR__"zhengting",
                "west":__DIR__"wuchang1",
                "east":__DIR__"wuchang2",
                
	]));
	set("objects",([
	     "/d/clone/npc/liguan":1,
	    ]));
       set("no_fight",1);
       set("outdoors", "slwg");
	setup();
}

