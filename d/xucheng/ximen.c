
#include <room.h>

inherit ROOM;
void create()
{
	set("short", "许城西门");
	set("long", @LONG
这是西城门，城门正上方刻得有个大大的＂魏＂字。城墙上贴着几
张官府告示。一条大路往北通向河北。
LONG );
	set("exits", ([
		"east" : __DIR__"xidajie",
		"west" : __DIR__"dadao",
	]));
	set("objects", ([
		__DIR__"npc/bing" : 2,
		__DIR__"npc/wujiang":1,
	]));
	set("outdoors", "xucheng");
	setup();
	replace_program(ROOM);
}

