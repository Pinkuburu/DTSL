
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", GRN"草地"NOR);
	set("long", @LONG
这里是一片草地。北面是东溟派的练武场。南边是一个长廊。从这
里可以听到练武场吆喝的声音。几名弟子从你的身边匆匆而过。
LONG);
	set("exits", ([
	     
		
		"north":__DIR__"wuchang",
	
		"south":__DIR__"echanglang2",
		
		
	]));

        
       set("valid_startroom", 1);   
       set("outdoors", "青石路");  
	setup();
       
       
}

