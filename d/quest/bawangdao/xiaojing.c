
#include <room.h>

inherit ROOM;
void create()
{
	set("short", "小径");
	set("long", @LONG
这是一条小径，曲曲折折，不知道能通向什么地方。四周是美丽的
景物。这里清雅幽静，令人感觉非常舒服。
LONG
	);


	set("exits", ([
		"east" :"/d/chengdu/wu",
		"north":__DIR__"xiaojing2",
	]));
       set("outdoors", "成都");
	setup();
}

