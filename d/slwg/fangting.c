
#include <room.h>

inherit ROOM;
void create()
{
	set("short", "方厅");
	set("long", @LONG
这里是石龙武馆练功的地方了。东边、南边、北边有三个练功房，
石龙武馆的弟子就是在那里练习武艺。不时从那里传来呼喝的声音，
听起来非常热闹。
LONG
);


	set("exits", ([
		"northwest" :__DIR__"donglang2",
                "east":__DIR__"liangongfang2",
                "north":__DIR__"liangongfang1",
                "south":__DIR__"liangongfang3",
                
	]));
	/*set("objects",([
	    __DIR__"npc/shoumen_dizi":1,
	    ]));*/
       set("no_fight",1);
      // set("outdoors", "slwg");
	setup();
}
