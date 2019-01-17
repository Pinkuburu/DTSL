inherit ROOM;

void create()
{
	set("short", "兵营");
	set("long", @LONG
这里是兵营，密密麻麻到处都是官兵，有的在武将的指挥下列队操
练，有的独自在练功，有的坐着、躺着正在休息。南墙下坐着主帅，不
动声色地寻视着四周。看到你进来，他们全都向你瞪大眼睛盯着你。
LONG );

	set("exits", ([
		"east" : __DIR__"beidajie",
	]));
	set("objects", ([
		__DIR__"npc/xuan" : 1,
		__DIR__"npc/guan"  : 1,
		__DIR__"npc/bing" : 2,
	]));
	setup();
	replace_program(ROOM);
}

