inherit ROOM;

void create()
{
	set("short", "小山包");
	set("long", @LONG
这里是一个小山包。向东边遥遥望去，可以看到金墉城，向西边遥
遥望去，可以看到洛阳城和一座寺院。
LONG );

	set("exits", ([
                         "eastdown"      : __DIR__"xiaolu2",
                         "westdown"      : __DIR__"shanlu1",
		
	]));
	set("outdoors", "xingyang");
	setup();
	replace_program(ROOM);
}



