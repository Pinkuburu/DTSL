// /d/taiyuan/road5.c
// Room in 太原
// modify by yang

inherit ROOM;

void create()
{
	set("short", "大驿道");
	set("long", @LONG
你走在一条尘土飞扬的大驿道上。北上就是涿郡城。挑担子行商的、
赶着大车的马夫熙熙攘攘，非常热闹。不时还有两三骑快马从身边飞驰而
过，扬起一路尘埃。
LONG );
	set("exits", ([
                "south" : __DIR__"road7-1",
		"northeast" : __DIR__"road6",
		"southwest" : __DIR__"road4",
		
	]));
	set("outdoors", "taiyuan");
	setup();
	replace_program(ROOM);
}



