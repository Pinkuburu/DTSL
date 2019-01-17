inherit ROOM;

void create()
{
	set("short", "大驿道");
	set("long", @LONG
你走在一条尘土飞扬的大驿道上。虽然现今天下大乱，但是四周还
是人来人往。挑担子的、行商的、赶着大车的马夫，熙熙攘攘，非常热
闹。南边已经靠近黄河的北岸了，可以听到黄河流水的声音。
LONG );

	set("exits", ([
               "east"      : __DIR__"dadao7",
               "southwest":__DIR__"dadao9",
		
	]));


 	set("outdoors", "liyang");
	setup();
	replace_program(ROOM);
}



