#include <room.h>

inherit ROOM;
void create()
{
	set("short", "浮桥");
	set("long", @LONG
这是河是彭梁和许城的界河，过了这条河就是许城的地界了，河上
架有行军用的浮桥，浮桥不是很宽，但过一辆马车还是合适的。
LONG );
	set("exits", ([
		"east"     : __DIR__"heyan",
		"west"     : "/d/xucheng/dadao6",
	]));
	set("outdoors", "pingliang");
	setup();
	replace_program(ROOM);
}

