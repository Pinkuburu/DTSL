

inherit ROOM;

void create()
{
	set("short", "南侧街");
	set("long", @LONG
这是一条普通的青石板路，南边通向南侧门，北边就是东大街。这
里的行人不是很多。
LONG);
        set("outdoors", "成都");

	set("exits", ([
        "north" : __DIR__"dadongmen",
		"south" : __DIR__"nancejie2",
	]));

	setup();
	replace_program(ROOM);
}

