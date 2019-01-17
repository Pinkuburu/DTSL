// /d/yuyang/edao1
// Room in 渔阳
inherit ROOM;

void create()
{
	set("short", "岔路口");
	set("long", @LONG
你走到一个三岔路口，向北是通向渔阳的大路，再向东走就要进入
乐寿的地界了，向西你就要进入山西的地界了。
LONG
	);

	set("exits", ([
                "southwest" : __DIR__"edao13",
                "northeast" : __DIR__"edao7",
                "southeast" : "/d/leshou/dadao1",
	]));

 	set("outdoors", "/d/yuayng");
	setup();
	replace_program(ROOM);
}


