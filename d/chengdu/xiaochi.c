

inherit ROOM;

void create()
{
	set("short", "蜀中小吃店");
	set("long", @LONG
这里是家小吃店。门前的幌子在风中摇摆不定，老远就看得清清楚
楚。由于成都基本没有受到战乱的干扰，所以这里生意还是很不错。店
小二正在门口招呼来往的行人。
LONG);
        //set("outdoors", "成都");

	set("exits", ([
	
	
		"south" : __DIR__"dongdajie2",
	]));
	set("objects",([
		__DIR__"npc/xiaoer":1,
		]));

	setup();
	replace_program(ROOM);
}

