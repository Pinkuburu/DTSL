
#include <room.h>

inherit ROOM;

string look_gaoshi();

void create()
{
	set("short", "大东门");
	set("long", @LONG
这是就是成都的东城门了。成都地处川中，一向少有战事困扰，所
以很少见到有士兵。几个百姓朝城中走去。
LONG);


	set("exits", ([
        "west" : __DIR__"dongdajie2",
        "south" : __DIR__"nancejie1",
		"east" : __DIR__"dadao1",
	]));
	set("object",([
		__DIR__"npc/bing":2,
		]));
        set("outdoors", "成都");
	setup();
}


