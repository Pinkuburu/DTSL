
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", GRN"木屋"NOR);
	set("long", @LONG
这里是一个木屋。这是东溟派女弟子居住的地方。床上的被褥叠得
整整齐齐。这里散发着淡淡的香气。
LONG);
	set("exits", ([
	     
		
		"west":__DIR__"shilu2",
	
		]));
       
       set("valid_startroom", 1);   
      // set("outdoors", "青石路");  
	setup();
       
       
}

