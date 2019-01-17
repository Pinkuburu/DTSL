inherit ROOM;


void create()
{
	set("short", "街道");
	set("long", @LONG
这里是彭城的南北的主干道，彭城毁于契丹马贼之手，少帅军占领
彭梁以后，开始重建彭城，工程好象还在继续，街道的两旁房屋有的刚
刚建好，有的还在架设房屋的主架．南面传来叮当的打铁声。
LONG
	);
        set("outdoors", "pengliang");


	set("exits", ([
		"north" : __DIR__"beichengmen",
                "south" : __DIR__"tiepu",
                 "southwest" : __DIR__"jiedao2",
                "southeast" : __DIR__"jiedao3",
	]));
	setup();
	replace_program(ROOM);
}

