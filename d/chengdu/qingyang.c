
inherit ROOM;

void create()
{
	set("short", "青羊宫");
	set("long", @LONG
这是成都的青羊宫。它是成都里最大的道观，香火十分鼎盛，每天
来烧香的人十分多。成都这几天聚集了很多武林人士，所以独尊堡自然
也派出了很多弟子出来巡视。
LONG
	);
        set("outdoors", "成都");

	set("exits", ([
		"west" : __DIR__"nandajie1",
	]));
  
	setup();
	replace_program(ROOM);
}

