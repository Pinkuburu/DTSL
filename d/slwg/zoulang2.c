
#include <room.h>

inherit ROOM;
void create()
{
	set("short", "走廊");
	set("long", @LONG
这里是石龙武馆的走廊。南边是武馆的大门。北边就是武馆的正厅
了。有很多弟子在这里走来走去，看起来非常热闹。东边不时传来呼喝
练武的声音。
LONG
);


	set("exits", ([
		"northup" :__DIR__"zhengting",
                "south":__DIR__"zoulang1",
	]));
	/*set("objects",([
	    __DIR__"npc/shoumen_dizi":1,
	    ]));*/
       set("no_fight",1);
       set("outdoors", "slwg");
	setup();
}
