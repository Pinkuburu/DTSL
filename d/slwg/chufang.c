
#include <room.h>

inherit ROOM;
void create()
{
	set("short", "厨房");
	set("long", @LONG
这里是石龙武馆的厨房，有几个厨子正在这里忙着做饭。只见这里
香气扑鼻，有很多做好的饭菜放在了桌子上。有几个弟子正在那里狼吞
虎咽地吃着。
LONG
);


	set("exits", ([
		"south" :__DIR__"xilang2",
		
	]));
	set("objects",([
	    __DIR__"npc/chuzi":1,
	    ]));
	set("resource/water",1);
       set("no_fight",1);
       //set("outdoors", "slwg");
	setup();
}
