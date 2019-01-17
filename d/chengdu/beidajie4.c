

inherit ROOM;

void create()
{
	set("short", "北大街");
	set("long", @LONG
这是一条宽阔的青石街道，向南北两头延伸。北边是北城门通向城
外。南边显得很繁忙。东边有家客店。西边是通往郊区的一条大路，这
条路的尽头就是成都的解家堡了。
LONG);
        set("outdoors", "成都");

	set("exits", ([
		
		"south" : __DIR__"beidajie3",
		"north":__DIR__"dabeimen",
		"east":__DIR__"kedian",
		"west":__DIR__"dalu1",
		
	]));

	setup();
	replace_program(ROOM);
}

