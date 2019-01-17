inherit ROOM;

void create()
{
	set("short", "石桥");
	set("long", @LONG
这是一座刚刚建成的石桥，由有青石垒成。桥下的河水清可见底。
几条小鱼在河底游来游去。由此向南就是下邳城了。
LONG );
	set("exits", ([
		"northwest" : __DIR__"edao3",
		"south" : __DIR__"xiapi",
	]));
	set("outdoors", "pengliang");
	setup();
	replace_program(ROOM);
}

