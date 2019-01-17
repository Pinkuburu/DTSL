
#include <room.h>

inherit ROOM;

string look_gaoshi();

void create()
{
	set("short", "栈道");
	set("long", @LONG
这是这里是进出蜀地的栈道。俗话说“蜀道难，难于上青天”。一
边是高崇入云的山峰，一边是万丈深渊，你走在栈道上不禁有些提心吊
胆。
LONG);


	set("exits", ([
		"southwest" : __DIR__"zhandao1",
		"northwest" : __DIR__"zhandao3",
	]));
        set("outdoors", "成都");
	setup();
}


