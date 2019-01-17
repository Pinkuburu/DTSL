// Room: /d/longyan/hotel.c

inherit ROOM;

void create()
{
	set("short", "有间客栈");
	set("long", @LONG
这里就是远近闻名的“有间客栈”。虽说龙眼村不算大，
但是其繁华程度也不亚于某些都城。就这客栈来说吧，只见门
外两只大红灯笼高高地悬挂在门口，每逢夜晚就会亮起，照得
整个集市一条街灯火通明。再看客栈内部，红漆桌椅，陶瓷酒
杯，甚显客栈气派。几名店小二肩披毛巾，不停地在里外忙来
忙去，不亦乐乎。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"mktstr2",
]));

	setup();
	replace_program(ROOM);
}
