
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", GRN"石阶"NOR);
	set("long", @LONG
这里是一级级的向上的石阶。你已经走在碧宵宫中。这里种了很多
鲜花。两边还种了很多青竹。
LONG);
	set("exits", ([
	     
		"southup" :__DIR__"shijie2",
		"northdown":__DIR__"door",
		
	]));
	
        
       set("valid_startroom", 1);   
       set("outdoors", "青石路");  
	setup();
       
       
}

