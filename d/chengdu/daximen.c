
#include <room.h>

inherit ROOM;

string look_gaoshi();

void create()
{
	set("short", "大西门");
	set("long", @LONG
这是就是成都的西城门了。成都地处川中，一向少有战事困扰，所
以很少见到有士兵。有几名百姓正在朝城中走去。
LONG);


	set("exits", ([
		"east" : __DIR__"xidajie2",
		"west":__DIR__"wroad1",
	]));
	set("object",([
		__DIR__"npc/bing":2,
		]));
        set("outdoors", "成都");
	setup();
}



