
#include <room.h>

inherit ROOM;
void create()
{
	set("short", "西廊");
	set("long", @LONG
这里是石龙武馆的西厢廊。继续往西边走，就是武馆的厨房和休息
室了。东边是武馆的正厅。厢廊的两旁是不大不小的荷花池，里面荷花
盛开，非常漂亮。
LONG
);


	set("exits", ([
		"southwest" :__DIR__"xilang2",
                "east":__DIR__"zhengting",
                
	]));
	/*set("objects",([
	    __DIR__"npc/shoumen_dizi":1,
	    ]));*/
       set("no_fight",1);
       set("outdoors", "slwg");
	setup();
}
