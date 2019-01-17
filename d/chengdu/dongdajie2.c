
inherit ROOM;

void create()
{
	set("short", "东大街");
	set("long", @LONG
这是成都的东大街。东边通向东城门，西边显得很繁忙。南边有一
座大宅邸，不知是哪个世家贵族所居。北边是一家小吃店，里面传来了
阵阵的饭菜香。
LONG);
        set("outdoors", "成都");

	set("exits", ([
		"east" : __DIR__"dadongmen",
		"west" : __DIR__"dongdajie1",
		"south" : __DIR__"door",
		"north":__DIR__"xiaochi",
	]));
	
	set("objects",([
	   "/d/job/questjob/npc/baiwenyuan":1,
	   ]));

	setup();
	replace_program(ROOM);
}

