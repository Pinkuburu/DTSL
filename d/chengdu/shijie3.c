
inherit ROOM;

void create()
{
	set("short", "石阶");
	set("long", @LONG
这是一条通往西面阁楼的石阶.
LONG);
	set("exits", ([
		"westup" : __DIR__"shijie4",
		
		"eastdown" : __DIR__"shijie2",
	]));

	setup(); 
	replace_program(ROOM);
}
