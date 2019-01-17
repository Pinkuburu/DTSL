
#include <room.h>

inherit ROOM;
string do_look1();
string do_look2();
int do_nothing(string arg);
void create()
{
	set("short", "密室");
	set("long", @LONG
这是一个密室。上面是一个坟地。这里没有阳光，只有上面洞中漏
下的丝丝光线。这里有个水潭，旁边还有几个苹果，看来这里是休息的
地方。
LONG
	);


	set("exits", ([
		"east" :__DIR__"mishi",
	]));
	set("resource/water",1);
	set("sleep_room",1);
	set("objects",([
	__DIR__"pingguo":3,
	]));
	set("no_channel","你还是专心练功吧！\n");
 	setup();
}
  
