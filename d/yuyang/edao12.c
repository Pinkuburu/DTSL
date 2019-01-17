// /d/yuyang/edao1
// Room in 渔阳
inherit ROOM;

void create()
{
	set("short", "大驿道");
	set("long", @LONG
你走在一条尘土飞扬的大驿道上。四周人来人往。挑担子的行商，
赶着大车的马夫，熙熙攘攘，非常热闹。不时还有两三骑快马从身边飞
驰而过，扬起一路尘埃。道路两旁是整整齐齐的杨树林。
LONG
	);

	set("exits", ([
		"south" : "/d/leshou/eroad3",
                "northeast" : __DIR__"edao11",
	]));

 	set("outdoors", "/d/yuayng");
	setup();
	replace_program(ROOM);
}


