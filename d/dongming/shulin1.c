
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", GRN"树林"NOR);
	set("long", @LONG
这里是片树林。南方可以隐隐看见东溟派的山门。有几名东溟派的
弟子从那里走了过来，正在谈论着什么。
LONG);
	set("exits", ([
	     
		
		
		"south":__DIR__"door",
		"north":__DIR__"huayuan1",
		"east":__DIR__"shulin3",
		
		
	]));

        
       set("valid_startroom", 1);   
       set("outdoors", "青石路");  
	setup();
       
       
}

