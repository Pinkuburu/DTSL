inherit ROOM;


void create()
{
	set("short", "北门");
	set("long", @LONG
这是北城门，城门正上方刻着“北门”两个楷书大字。官兵们警惕
地注视着过往行人，你最好小心为妙。一条笔直的青石板大道向南北两
边延伸。
LONG
	);
        set("outdoors", "pengliang");


	set("exits", ([
		"north" : __DIR__"edao5",
                "south" : __DIR__"beidajie",
	]));
         set("objects", ([
		__DIR__"npc/bing" : 2
	]));
	setup();
	replace_program(ROOM);
}

