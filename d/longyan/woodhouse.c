// Room: /d/longyan/woodhouse.c

inherit ROOM;

void create()
{
	set("short", "小木屋");
	set("long", @LONG
这里是田间的一间小木屋，屋里坐着一位五十多岁的老汉
看来是这片田地的主人。这里陈设朴实，一张木桌一张木床是
这里唯一的家具，屋子角落里有几罗刚收上来的小麦。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"field1",
]));

	setup();
	replace_program(ROOM);
}
