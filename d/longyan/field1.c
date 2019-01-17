// Room: /d/longyan/field1.c

inherit ROOM;

void create()
{
	set("short", "田间小路");
	set("long", @LONG
这里是一条羊肠小路，两旁是一望无垠的小麦田地，微风
吹过，田地中泛起阵阵麦浪，两旁的稻草人也随风摇摆，一片
美丽的田间景象。向南望去，一个小木屋坐在那里，想必就是
农田主人的家了。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"woodhouse",
  "north" : __DIR__"center",
]));

	setup();
	replace_program(ROOM);
}
