
#include <room.h>

inherit ROOM;
void create()
{
	set("short", "卧室");
	set("long", @LONG
这里是馆主石龙的卧室，这里收拾的非常干净。屋子的里面摆着一
张大床，床头上放着几本武学的书籍。屋子左边的墙上挂着一把钢剑，
冒着阵阵寒气。
LONG
);


	set("exits", ([
		"west" :__DIR__"caodi",
                
	]));
	/*set("objects",([
	    __DIR__"npc/shoumen_dizi":1,
	    ]));*/
       set("no_fight",1);
       //set("outdoors", "slwg");
	setup();
}
