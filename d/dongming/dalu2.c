
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "大路");
	set("long", @LONG
这里是一条宽敞的大路。北边可以隐隐约约看见杭州的城墙了。这
里的人很多，大多是到杭州游玩的。
LONG);
	set("exits", ([
		"south":__DIR__"dalu1",
		"northeast":__DIR__"dalu3",
		]));
      set("valid_startroom", 1);   
       set("outdoors", "青石路");  
	setup();
       
       
}

