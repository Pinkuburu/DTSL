// /d/gaoli/chengqiangshang2
// Room in 山海关
// rich 99/04/05
inherit ROOM;
void create()	
{
	set("short", "城墙上");
	set("long", @LONG
你站在山海关的城墙上，因为军事的原因山海关的城墙修的
特别坚固，北面是长城的烽火台，东边是山海关的南城楼。
LONG
	);
set("outdoors", "/d/shanhaiguan");
set("exits", ([
		"north" : __DIR__"fenghuotai",
	        "east" : __DIR__"nanchenglou",
            	"eastdown" : __DIR__"nanchengmen",
	]));
       setup();
	replace_program(ROOM);
}	
