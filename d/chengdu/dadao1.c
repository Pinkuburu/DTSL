
#include <room.h>

inherit ROOM;

string look_gaoshi();

void create()
{
	set("short", "大道");
	set("long", @LONG
这是成都东门外的一条大路。西边是成都的东门。两边是一片片的
树林，据说很少有人进去能够再出来。再向东去就是栈道了。
LONG);


	set("exits", ([
		"west" : __DIR__"dadongmen",
		"eastup" : __DIR__"zhandao1",
	]));
        set("outdoors", "成都");
	setup();
}


