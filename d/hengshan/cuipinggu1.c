// Room: /d/hengshan/cuipinggu1.c

inherit ROOM;

void create()
{
	set("short", "翠屏谷");
	set("long", @LONG
浑河在谷中冲刷而过，天峰岭和翠屏山分列峡谷两侧，绝壁千仞，
犹如刀削斧劈，高耸入云，这里自古就是塞外通往内地的咽喉要道，真
有一夫当关万夫莫开之势。
LONG
	);
	set("exits", ([
		"southeast"  : __DIR__"cuipinggu2",
		"northwest"  : __DIR__"jinlongxia",
	]));
	/*set("objects", ([
		__DIR__"npc/zei" : 1,
	]));*/
	set("outdoors", "hengshan");
	setup();
}

