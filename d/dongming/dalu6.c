
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "大路");
	set("long", @LONG
这里是一条大路。这里的行人渐渐多了起来，一条笔直的石板大道
通向前方，四周开始有一些吵杂的喧闹声音。
LONG);
	set("exits", ([
		"south":__DIR__"dalu5",
		"north":__DIR__"dalu7",
		]));
      set("valid_startroom", 1);   
       set("outdoors", "青石路");  
	setup();
       
       
}

