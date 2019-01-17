
inherit __DIR__"hole";

#include <ansi.h>

void create ()
{
	set ("short",BLU"山洞"NOR);
	set ("long", @LONG
这里是一个山洞，四下里漆黑一片，一股潮湿的气息扑鼻而来。四
周异常安静，但你隐隐约约可以感觉到一股杀气。地上有一个小土包，
似乎埋藏了什么东西。
LONG);

	set("exits", ([ 
		"north":__DIR__"shandong2",
		"south":__DIR__"shandong3",
		"west":__DIR__"shandong4",
		"east":__DIR__"shandong5",
		 
        ]));
  	set("no_quit",1);
  	setup();
 
}
