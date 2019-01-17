inherit ROOM;

void create()
{
	set("short", "东大街");
	set("long", @LONG
这是一条宽阔的青石板街道，向东西两头延伸。东大街是商贾所在，
行人来来往往，十分热闹。西边是彭梁的十字街口。南边是一家饭馆，北
面是一家客栈。
LONG
	);
       set("outdoors", "pengliang");

	set("exits", ([
		"west" : __DIR__"shizijietou",
		"south" : __DIR__"duyimei",
                "north" : __DIR__"kezhan",
		"east" : __DIR__"dongmen",
		
	]));

	setup();
	replace_program(ROOM);
}

