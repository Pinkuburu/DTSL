#include <room.h>

inherit ROOM;
void create()
{
	set("short", "营房");
	set("long", @LONG
这里是骠骑营的营房，一排排木屋煞是齐整, 门口空地许多军士们
围成个圈在喧闹，西夏军中崇尚勇力，佩服的是英雄，士兵个个都是彪
形大汉。
LONG );
	set("exits", ([
		"south" : __DIR__"junying",
	]));
	set("objects", ([
		__DIR__"npc/bing" :3,
	]));
	set("outdoors", "liyang");
	setup();
	replace_program(ROOM);
}

