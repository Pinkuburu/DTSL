// /d/zhuojun/dadao1.c
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
                //"northeast":__DIR__"dadao2",  
                "south":__DIR__"beimen", 
                "northwest":"/d/yuyang/chalu",   
	]));
       setup();
	replace_program(ROOM);
}
