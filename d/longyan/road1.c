// Room: /d/longyan/road1.c

inherit ROOM;

void create()
{
	set("short", "土路");
	set("long", @LONG
这里是一条土路，往南通向方圆百里最大的村庄——龙眼
村，往北是上黑松山的路，山路不太好走，前边似乎有一个小
亭。西面是一扇大门，里面装扮的十分现代，那里就是玩家的
登记处，也是这个世界与现实的连接点。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"center",
  "north" : __DIR__"tenting",
  "west" : "/d/wiz/check",
]));

	setup();
	replace_program(ROOM);
}
