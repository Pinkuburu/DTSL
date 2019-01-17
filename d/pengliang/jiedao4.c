inherit ROOM;


void create()
{
	set("short", "街道");
	set("long", @LONG
这里是彭城的南北的主干道，彭城毁于契丹马贼之手，少帅军占领
彭梁以后，开始重建彭城，工程好象还在继续，街道的两旁房屋有的刚
刚建好，有的还在架设房屋的主架。北面传来马叫的声音。
LONG
	);
        set("outdoors", "pengliang");


	set("exits", ([
		"north" : __DIR__"mafang",
                "south" : __DIR__"nanchengmen",
                 "northwest" : __DIR__"jiedao2",
                "northeast" : __DIR__"jiedao3",
	]));
	set("objects",([
	 __DIR__"npc/gongren":1,
	 ]));
	setup();
	replace_program(ROOM);
}

