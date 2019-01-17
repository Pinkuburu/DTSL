
inherit ROOM;

void create()
{
	set("short", "石阶");
	set("long", @LONG
这是一条通往西面阁楼的石阶。下面是一片青草地。这里静悄悄的，
平时没有什么人来，只有几个丫鬟从这里走过。
LONG);
	set("exits", ([
		"westup" : __DIR__"shijie2",
		
		"eastdown" : __DIR__"caodi3",
	]));

	setup(); 
	replace_program(ROOM);
}
