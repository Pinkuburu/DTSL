
inherit ROOM;

void create()
{
	set("short", "南大街");
	set("long", @LONG
这是一条宽阔的青石街道，向南北两头延伸。南边是南城门通向城
外。北边显得很繁忙。东边有一家兵器铺，里面传来了敲敲打打的声音。
LONG);
        set("outdoors", "成都");

	set("exits", ([
		"north" : __DIR__"nandajie1",
		"south" : __DIR__"dananmen",
		"east":__DIR__"bingqipu",
	]));
	set("objects",([
 "/d/job/killerjob/yangxu-yan":1,
		]));

	setup();
	replace_program(ROOM);
}

