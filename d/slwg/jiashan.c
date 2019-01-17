
#include <room.h>

inherit ROOM;
void create()
{
	set("short", "假山");
	set("long", @LONG
这里是一处假山，假山形状各异，造型奇特，再加上旁边花草树木
的点缀，把弄得的确是美丽非凡。北边就是石龙的书房，往动走，则可
以到石龙的卧室。
LONG
);


	set("exits", ([
		"northeast" :__DIR__"shufang",
                "southwest":__DIR__"beilang2",
                "east":__DIR__"caodi",
                
	]));
	set("objects",([
	    __DIR__"npc/yahuan":1,
	    ]));
       set("no_fight",1);
       set("outdoors", "slwg");
	setup();
}
