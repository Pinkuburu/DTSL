
#include <room.h>

inherit ROOM;
void create()
{
	set("short", "宫门");
	set("long", @LONG
这是许城皇宫的正门，这个皇宫是新建的，只能算是一个大点的庭
院。
LONG );
	set("exits", ([
		"south" : __DIR__"nanmen",
                 "northeast" : __DIR__"eastdao",  
                "northwest" : __DIR__"westdao",
		"east" : "/d/clone/room/cityroom/xucheng",
	]));
	/*set("objects", ([
		__DIR__"npc/weishi" : 2,
	]));*/
	set("outdoors", "xucheng");
	setup();
	replace_program(ROOM);
}

