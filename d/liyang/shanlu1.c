inherit ROOM;
void create()
{
	set("short", "林中大路");
	set("long", @LONG
这是山间的土路，勉强可以通行一辆大车，路面上有两条深深的车
辙印，路边山坡上全是参天巨木，看上去密不透风，这里很幽静，除了
偶尔几声鸟叫才能打破寂静。土路向北蜿蜒延伸转个弯。
LONG );
	set("exits", ([
		"southup"     : __DIR__"shanlu2",
		"eastdown" : __DIR__"dadao2",
	]));
	set("no_clean_up", 0);
	set("outdoors", "liyang");
	setup();
	replace_program(ROOM);
}

