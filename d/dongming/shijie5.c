
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", GRN"石阶"NOR);
	set("long", @LONG
这里是石阶。这里有很多弟子在跑来跑去，似乎在忙着些什么。这
里种了很多鲜花。两边还种了很多青竹。
LONG);
	set("exits", ([
	     
		
		"northup":__DIR__"pinglu",
	
		"southdown":__DIR__"shijie4",
		
		
	]));

        
       set("valid_startroom", 1);   
       set("outdoors", "青石路");  
	setup();
       
       
}

