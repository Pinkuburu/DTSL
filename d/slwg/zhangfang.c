
#include <room.h>

inherit ROOM;
void create()
{
	set("short", "账房");
	set("long", @LONG
这里是石龙武馆的账房，平时有账房先生在这里收钱。许多来武馆
里学习武艺的弟子都要到这里交学费的。同时每个弟子在这里也可以领
取自己的存款。
LONG
);


	set("exits", ([
		"west" :__DIR__"zoulang1",
     ]));
	set("objects",([
	    __DIR__"npc/zhangfang_xiansheng":1,
	    ]));
       set("no_fight",1);
      setup();
}
