
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", HIW"瀑布"NOR);
	set("long", @LONG
这里是一个瀑布。这里只听得轰隆隆的声音。瀑布垂直而下，景色
极为壮观。
LONG);
	set("exits", ([
		"west":__DIR__"shulin2",
		]));
      set("valid_startroom", 1);   
       set("outdoors", "青石路");  
	setup();
       
       
}

