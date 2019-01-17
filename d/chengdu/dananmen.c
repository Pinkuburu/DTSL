
#include <room.h>

inherit ROOM;

string look_gaoshi();

void create()
{
	set("short", "大南门");
	set("long", @LONG
这是就是成都的南城门了。成都地处川中，一向少有战事困扰，所
以很少见到有士兵。
LONG);


	set("exits", ([
		"north" : __DIR__"nandajie2",
    	"south" : __DIR__"tulu3",
	]));
	set("object",([
		__DIR__"npc/bing":2,
		]));
        set("outdoors", "成都");
	setup();
}



