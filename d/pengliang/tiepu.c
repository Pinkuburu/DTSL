inherit ROOM;


void create()
{
	set("short", "铁匠铺");
	set("long", @LONG
这里原来是一家极其简陋的铁匠铺。由于宇文化及进犯彭梁，这家
铁匠铺被少帅军征用，作为官办作坊。目前规模很大，一般用来为少帅
军打造铠甲、兵器等，以及制造筹备守城物资。只见几十个铁匠正叮叮
当当地忙个不停。
LONG
	);
    
	set("exits", ([
		"north" : __DIR__"jiedao1",
	]));
         set("objects", ([
		__DIR__"npc/tiejiang" : 1
	]));
	setup();
	replace_program(ROOM);
}

