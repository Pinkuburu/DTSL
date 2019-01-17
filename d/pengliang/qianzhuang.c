inherit ROOM;

void create()
{
	set("short", "钱庄");
	set("long", @LONG
这是一家以信誉著称的钱庄，一个五尺高的柜台挡在你的面前，柜
台上摆着一个牌子(paizi)，柜台后坐着老板，一双精明上上下下打量着
你。
LONG
	);

	set("item_desc", ([
		"paizi" : "童叟无欺\n",
	]));
	
	set("exits", ([
		"south" : __DIR__"xidajie",
	]));
          set("objects", ([
                __DIR__"npc/qian" : 1
	]));
	setup();
	replace_program(ROOM);
}

