
inherit ROOM;

void create()
{
	set("short", "南大街");
	set("long", @LONG
这是成都的南大街。南边通向南城门，北边是城中心，那里传来了
热闹的声音。成都这几天聚集了很多武林人士，所以独尊堡自然也派出
了很多弟子出来巡视。远处有几名独尊堡的弟子正在朝这里走来。
LONG
	);
        set("outdoors", "成都");

	set("exits", ([
		"south" : __DIR__"nandajie2",
		"north" : __DIR__"center",
		"east" : __DIR__"qingyang",
	]));
  
	set("objects",([
		__DIR__"npc/fanzhuo":1,
		]));
	setup();
	replace_program(ROOM);
}

