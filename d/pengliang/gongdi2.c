inherit ROOM;


void create()
{
	set("short", "工地");
	set("long", @LONG
这里原来是彭城的东西的主干道的一部分，彭城毁于契丹马贼之手，
少帅军占领彭梁以后，开始重建彭城，工程好象还在继续，工人门来来往
往忙个不停。
LONG
	);
        set("outdoors", "pengliang");


	set("exits", ([
                "west" : __DIR__"jiedao2",
	]));
	setup();
	replace_program(ROOM);
}

