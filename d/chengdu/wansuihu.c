

inherit ROOM;

void create()
{
	set("short", "万岁湖");
	set("long", @LONG
这是万岁湖。湖面波平浪静。南边可以看到一座城堡，那就是名震
四川的独尊堡了。
LONG
	);
        set("outdoors", "成都");

	set("exits", ([
		"east":__DIR__"dalu1",
		"southwest":__DIR__"hubianlu",
		
	]));

	setup();
	replace_program(ROOM);
}

