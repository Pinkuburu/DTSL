
#include <room.h>

inherit ROOM;
void create()
{
	set("short", "书房");
	set("long", @LONG
这里是石龙的书房。这里并排放了三排书架，上面有很多武学方面
的书籍。屋子的中间放了一张大桌子，上面放着文房四宝。屋子右边的
墙壁上还挂着一口宝剑。
LONG
);


	set("exits", ([
		"southwest" :__DIR__"jiashan",
                
                
	]));
	/*set("objects",([
	    __DIR__"npc/shoumen_dizi":1,
	    ]));*/
       set("no_fight",1);
      // set("outdoors", "slwg");
	setup();
}
