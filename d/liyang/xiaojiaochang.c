inherit ROOM;
void create()
{
	set("short", "小校场");
	set("long", @LONG
这里是骠骑营的小校场，平时军士们就在这里操练，地上很平整，
居中是指挥台，有根长达数丈的旗杆，杆顶一面绣着一条红龙的骠骑营
白色军旗迎风猎猎作响。平时军士们一天三练，早上出操，中午出城练
马术和野战，晚上则负责皇城外的巡逻。
LONG );
	set("exits", ([
		"north" : __DIR__"junying",
	]));
	set("objects", ([
		__DIR__"npc/bing" :3,
	]));
	set("outdoors", "liyang");
	setup();
	replace_program(ROOM);
}

