// /d/gaoli/nandajie1
// Room in 山海关
// rich 99/04/05
inherit ROOM;
void create()	
{
	set("short", "南大街");
	set("long", @LONG
这里的路相当的宽，能容好几匹马车并行，长长的道路贯穿南北，
这里山海关的南大街，因为山海关是塞外和中原必经之路，所以来往的
客商特别多，东边是一家小酒馆，南边是山海关的南门。
LONG
	);
set("outdoors", "/d/shanhaiguan");
set("exits", ([
		"north" : __DIR__"guangchang",
		"south" : __DIR__"nanchengmen",
                "east" : __DIR__"xiaojiuguan",       
	]));
    set("objects",([
        __DIR__"npc/xunbu":1,
        ]));
       setup();
	replace_program(ROOM);
}	
