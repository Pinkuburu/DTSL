// /d/shanhaiguan/dadao1.c
// Room in 山海关
// modify by yang

inherit ROOM;
void create()	
{
	set("short", "青石大道");
	set("long", @LONG
你走在一条青石大道上，人来人往非常繁忙，不时地有人骑着马匆
匆而过。
LONG
        );
set("outdoors", "/d/shanhaiguan");
set("exits", ([
                "north":__DIR__"dadao2",  
                "westup":__DIR__"qingshilu",
                "south":__DIR__"dadao1-1", 

	]));
       setup();
	replace_program(ROOM);
}
