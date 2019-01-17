
inherit ROOM;

void create()
{
	set("short", "城中心");
	set("long", @LONG
这里是成都的城中心，是一个热闹的小广场，铺着青石地面。这里
有很多打把势、卖艺的人，三五成群，非常热闹。不时有几名独尊堡的
弟子从你的身旁走过，穿戴整齐，看起来十分威风。成都地处蜀中，这
里的战乱还不是十分地明显。
LONG);
        set("outdoors", "成都");

	set("exits", ([
		"east" : __DIR__"dongdajie1",
		"west" : __DIR__"xidajie1",
		"south" : __DIR__"nandajie1",
		"north" : __DIR__"beidajie3",
	]));
	set("objects",([
		__DIR__"npc/xiaojie":1,
		__DIR__"npc/wushi":1,
		]));

	setup();
	replace_program(ROOM);
}

