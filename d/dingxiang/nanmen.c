// /d/yazhang/nanmen
// Room in 牙帐
// rich 99/05/17
inherit ROOM;
void create()	
{
	set("short", "南门");
	set("long", @LONG
东突厥是草原的霸主，故定襄城建的非同一般，城墙足有三丈高，
城门建的又高又大，足可让马并行。
LONG
	);
set("outdoors", "/d/yazhang");
set("exits", ([
		"south" : __DIR__"guandao1",
		"north" : __DIR__"nandajie1", 
	]));
	set("objects",([
	"/d/tujue/dun":1,
	]));
       setup();
	replace_program(ROOM);
}	
