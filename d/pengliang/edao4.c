inherit ROOM;

void create()
{
	set("short", "大道");
	set("long", @LONG
你走在一条碎石铺成的大道上，道两旁种着笔直通天的白杨树，放
眼向两侧望去，全是无边无际的田野，天边处仿佛有几座低矮的丘陵，
为平坦的大地增加了几许柔和的曲线。路上行人渐渐稀少起来。
LONG );
	set("exits", ([
		"east" : __DIR__"ximen",
		"northwest" : __DIR__"dadao1",
	]));
 	set("outdoors", "pengliang");
	setup();
	replace_program(ROOM);
}

