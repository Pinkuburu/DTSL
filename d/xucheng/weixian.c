inherit ROOM;

void create()
{
	set("short", "魏县");
	set("long", @LONG
这里就是魏地的重镇魏县了，魏县在永定渠的东岸，魏县是控
制永定渠的关键地点之一，现在天下大乱，各路英豪接竿而起，战
火不断，这里的驻军就明显增多，而且对过往的客商盘查的十分严
格，不时有快马从城里飞驰而过。	
LONG );

	set("exits", ([
	        "east"      : __DIR__"shanlu",
		"southwest"      : __DIR__"edao",
		
	]));


 	set("outdoors", "xucheng");
	setup();
	replace_program(ROOM);
}



