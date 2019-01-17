// Room: /d/longyan/center.c

inherit ROOM;

void create()
{
	set("short", "槐树下");
	set("long", @LONG
这里是龙眼村中央的集市，龙眼村是附近的大村，所以每
到农收时，这里便成了人们赶集的地方。这里有一棵百年的大
槐树，所以人们习惯的管这里叫槐树下。向西走就是集市了，
向北走是一条小山路，向南是一望无垠的麦田。
LONG
	);
	set("outdoor", "1");
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"field1",
  "east" : __DIR__"road2",
  "north" : __DIR__"road1",
  "west" : __DIR__"mktstr1",
]));

	setup();
	replace_program(ROOM);
}
