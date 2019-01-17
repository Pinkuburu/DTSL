inherit ROOM;

void create()
{
	set("short", "山道");
	set("long", @LONG
这是城北的一条山路，路旁杂乱的长着齐膝的荒草，远近荒无一人。
两旁干枯的老树上落满了成群的乌鸦，凄凉的鸣叫声在荒野上远远传去，
一派凄凉的景象。
LONG );
	set("exits", ([
		"northeast" : __DIR__"edao5",
                "westup" : __DIR__"shanlu2",
	]));
	set("objects",([
     "/d/clone/npc/yuwenwudi":1,
     ]));
 	set("outdoors", "pengliang");
	setup();
	replace_program(ROOM);
}

