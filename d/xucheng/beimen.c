
#include <room.h>

inherit ROOM;
void create()
{
	set("short", "许城北门");
	set("long", @LONG
这是北城门，城门正上方刻得有个大大的“魏”字。城墙上贴着几
张官府告示。一条大路往北通向山西。
LONG );
	set("exits", ([
		"north" : __DIR__"dadao10",
		"south" : __DIR__"beidajie",
	]));
	set("objects", ([
		__DIR__"npc/bing" : 2,
		__DIR__"npc/wujiang":1,
	]));
	set("outdoors", "xucheng");
	setup();
	replace_program(ROOM);
}

