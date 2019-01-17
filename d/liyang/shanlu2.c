inherit ROOM;
void create()
{
	set("short", "林中小路");
	set("long", @LONG
这是陡坡上的一条杂草丛生的羊肠小路，看起来平时没什么人迹，
路边开着不知名的野花，两边的松树依然高大、挺拔。阳光透下来照的
你身上是斑斑驳驳的影子。
LONG );
	set("exits", ([
		"southwest"     : __DIR__"shanlu3",
		"northdown"     : __DIR__"shanlu1",
	]));
	set("objects", ([
		__DIR__"npc/yetu" : 1,
	]));
	set("outdoors", "liyang");
	setup();
	replace_program(ROOM);
}

