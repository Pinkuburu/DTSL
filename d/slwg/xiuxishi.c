
#include <room.h>

inherit ROOM;
void create()
{
	set("short", "休息室");
	set("long", @LONG
这里是武馆弟子休息睡觉的地方。这里摆着很多床，有几个弟子从
外面进来，胡乱地找了张床就睡下了。这里鼾声连天，你不由得有些困
倦了。
LONG
);


	set("exits", ([
		"northeast" :__DIR__"huayuan",
		  
	]));
	/*set("objects",([
	    __DIR__"npc/shoumen_dizi":1,
	    ]));*/
       set("sleep_room",1);
       //set("outdoors", "slwg");
	setup();
}
