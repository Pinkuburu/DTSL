
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "山路");
	set("long", @LONG
这里是一条山路。这里已经是江西的境地了。你举目四望，不禁为
周围的景色所吸引住了。
LONG);
	set("exits", ([
		"southeast":__DIR__"shanlu5",
		"north":__DIR__"dalu5",
		]));
      set("valid_startroom", 1);   
       set("outdoors", "青石路");  
	setup();
       
       
}

