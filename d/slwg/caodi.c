
#include <room.h>

inherit ROOM;
void create()
{
	set("short", "草地");
	set("long", @LONG
这里是一片碧绿、松软的草地，走在上面非常舒服。西边是假山园
林，东边是石龙的卧室了。有几个丫鬟从这里走过，微笑着向你打着招
呼。
LONG
);


	set("exits", ([
		"west" :__DIR__"jiashan",
                "east":__DIR__"woshi",
                
	]));
	/*set("objects",([
	    __DIR__"npc/shoumen_dizi":1,
	    ]));*/
       set("no_fight",1);
       set("outdoors", "slwg");
	setup();
}
