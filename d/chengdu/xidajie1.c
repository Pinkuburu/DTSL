
inherit ROOM;

void create()
{
	set("short", "西大街");
	set("long", @LONG
这是成都的西大街。西边通向西城门，东边是城中心，那边显得非
常热闹。街的南边有一家寺庙，庙门看起来非常破旧，门上的牌匾已经
模糊不清了。
LONG);
        set("outdoors", "成都");

	set("exits", ([
		"west" : __DIR__"xidajie2",
		"east" : __DIR__"center",
		"south":__DIR__"simiao",
		"north": "/d/clone/room/cityroom/chengdu",
	]));
	set("objects",([
		__DIR__"npc/tongtian":1,
		]));

	setup();
	replace_program(ROOM);
}

