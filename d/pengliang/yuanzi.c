inherit ROOM;

void create()
{
	set("short", "少帅府大院");
	set("long", @LONG
这里是少帅府的大院，只见大理石铺就的地面一尘不染，两个衣着
光鲜的小丫鬟认真的在擦洗两边的栏杆和柱子，不时有值班的卫士走过
来。向里望去，可以看到少帅府的大厅。
LONG );
	set("no_clean_up", 0);
	set("exits", ([
		"south" : __DIR__"damen",
		"north" : __DIR__"dating",
	]));
	setup();
	replace_program(ROOM);
}

