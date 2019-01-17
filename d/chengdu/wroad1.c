
#include <room.h>

inherit ROOM;

string look_gaoshi();

void create()
{
	set("short", "大路");
	set("long", @LONG
这是成都西门外的一条大路。西边是人迹罕至的郊区了。前面一片
小树林，据说很少有人进去能够再出来。
LONG);


	set("exits", ([
		"east" : __DIR__"daximen",
		"west":__DIR__"wroad2",
	]));
       set("outdoors", "成都");
	setup();
}



