
inherit ROOM;

void create()
{
	set("short", "石阶");
	set("long", @LONG
这是一条通往西面阁楼的石阶.
LONG);
	set("exits", ([
		"westup" : "/d/yinkui/door",
		
		"eastdown" : __DIR__"shijie5",
	]));

	setup(); 
	replace_program(ROOM);
}
