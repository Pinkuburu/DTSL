
inherit ROOM;

void create()
{
	set("short", "川南赌坊");
	set("long", @LONG
这是成都著名的[川南赌坊]。这也是成都一个著名的势力之一。霍
青桥是这里的老板，很少有人敢来这里捣乱。只见这里一张大屋子，分
散开有二十几张桌子，每张桌子都聚满了人，人人面红耳赤，呼叫的声
音不绝于耳。更有赌徒赤膊上身，双目同红，在赌桌上大喊大叫。几个
赌场的伙计四处巡视，看看是否有人在这里出千作弊。
LONG
	);

	set("exits", ([
		"south" : __DIR__"dongdajie1",
	]));
	set("objects",([
		__DIR__"npc/huoqing-qiao":1,
		]));


	setup();
	replace_program(ROOM);
}

