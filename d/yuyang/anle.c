


inherit ROOM;


void create()
{
	set("short", "安乐县");
	set("long", @LONG
安乐县是渔阳到山海关的必经之路，安乐帮是安乐的第一大帮。可
是前几天，的一场大屠杀使安乐帮的主要人物全部死亡，在东北的江湖
道上引起极大震动。
LONG);
	
	set("exits", ([
		"north" : "/d/shanhaiguan/dadao1",
                "south" : __DIR__"eroad",
                "northeast" : __DIR__"tulu2",
                "southwest" : __DIR__"shandao8",
	]));
    
	set("outdoors", "qiuci");
	setup();
	replace_program(ROOM);
}
