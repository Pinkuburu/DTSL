
#include <room.h>

inherit ROOM;
void create()
{
	set("short", "花园");
	set("long", @LONG
这里是一个花园，这里花的品种繁多，多是全国各地的名贵品种，
把这里点缀的异常漂亮。有几个没事的丫鬟正在这里赏花，有几个还在
那里嬉笑打闹。
LONG
);


	set("exits", ([
		"east" :__DIR__"xilang2",
		"southwest":__DIR__"xiuxishi",
                
	]));
	set("objects",([
	    __DIR__"npc/yahuan":1,
	    __DIR__"npc/zhangjiaotou":1,
	    ]));
       set("no_fight",1);
       set("outdoors", "slwg");
	setup();
}
