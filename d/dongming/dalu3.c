
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "大路");
	set("long", @LONG
这里是一条宽敞的大路。这里的景色非常优美，你不禁被深深地吸
引住了。
LONG);
	set("exits", ([
		"southwest":__DIR__"dalu2",
		"north":__DIR__"dalu4",
		]));
      set("valid_startroom", 1);   
       set("outdoors", "青石路");  
	setup();
       
       
}

