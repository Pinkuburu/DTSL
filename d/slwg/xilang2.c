
#include <room.h>

inherit ROOM;
void create()
{
	set("short", "西廊");
	set("long", @LONG
这里是石龙武馆的西厢廊。北边就是武馆的厨房，西边就是武馆的
休息室了。东边是武馆的正厅。厢廊的两旁是不大不小的荷花池，里面
荷花盛开，非常漂亮。
LONG
);


	set("exits", ([
		"west" :__DIR__"huayuan",
		"north":__DIR__"chufang",
                "northeast":__DIR__"xilang1",
                
	]));
	/*set("objects",([
	    __DIR__"npc/shoumen_dizi":1,
	    ]));*/
       set("no_fight",1);
       set("outdoors", "slwg");
	setup();
}
