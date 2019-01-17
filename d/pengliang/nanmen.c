inherit ROOM;

void create()
{
	set("short", "南门");
	set("long", @LONG
这是梁都的南门。彭梁是少帅军所驻扎的城市。现在来这里投靠的
人非常多。这里站着几个官兵，在检查来往的行人。
LONG );
        set("outdoors", "pengliang");
	set("no_clean_up", 0);

	set("exits", ([
		"north" : __DIR__"nandajie",
		"south" : "/d/xingyang/dadao4",
	]));
	set("objects",([
	__DIR__"npc/bing":2,
        __DIR__"npc/wujiang":1,
	]));
	setup();
	replace_program(ROOM);
}

