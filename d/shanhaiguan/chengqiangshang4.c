// /d/gaoli/chengqiangshang2
// Room in 山海关
// rich 99/04/05
inherit ROOM;
void create()	
{
	set("short", "城墙上");
	set("long", @LONG
你站在山海关的城墙上，因为军事的原因山海关的城墙修的特别坚
固，南面是长城的烽火台，东边是山海关的北城楼。
LONG
	);
set("outdoors", "/d/shanhaiguan");
set("exits", ([
		"south" : __DIR__"fenghuotai",
	        "east" : __DIR__"beichenglou",
            	"eastdown" : __DIR__"beichengmen",
	]));
       setup();
	replace_program(ROOM);
}	
