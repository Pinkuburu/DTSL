
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "小路");
	set("long", @LONG
这里是一条小路，南边是一个港口。这里的行人很少。西边就是武
夷山了，有几名游客从那里走了过来。
LONG);
	set("exits", ([
		"south":__DIR__"gangkou2",
		"westup":"/d/wuyishan/doupo3",
		]));
      set("valid_startroom", 1);   
       set("outdoors", "青石路");  
	setup();
       
       
}

