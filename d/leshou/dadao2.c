// /d/zhuojun/dadao2.c
// Room in 涿郡
// modify by yang

inherit ROOM;
void create()	
{
	set("short", "青石大道");
	set("long", @LONG
你走在一条青石大道上，此处人群稀少，四周也静悄悄的。
LONG
        );
set("outdoors", "/d/zhuojun");
set("exits", ([
                "northeast":__DIR__"dadao3",  
                "southwest":__DIR__"dadao1",    
	]));
       setup();
	replace_program(ROOM);
}
