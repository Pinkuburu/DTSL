
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", GRN"木屋"NOR);
	set("long", @LONG
这里是一个木屋。这里是东溟派入门弟子做工干活的地方。有很多
东溟派的弟子在这里干活。只见又一名弟子走了进来。
LONG);
	set("exits", ([
	     
		
		"east":__DIR__"pinglu",
	
		]));
	set("objects",([
		__DIR__"npc/zhang_popo":1,
		]));

        
       set("valid_startroom", 1);   
  	setup();
       
       
}

