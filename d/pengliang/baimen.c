inherit ROOM;

void create()
{
	set("short", "白门楼");
	set("long", @LONG
这就是有名的白门楼，门楼上有一把大椅，看起来古迹斑斑，据说
这就是吕布坐过的，是否是真的，谁也说不清。
LONG );
	set("exits", ([
		"northdown" : __DIR__"xiapi",
	]));
	set("outdoors", "pengliang");
	setup();
	replace_program(ROOM);
}

