
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", GRN"西廊"NOR);
	set("long", @LONG
这里是西廊。长廊的墙壁上画着一些精美的壁画，看起来笔迹不凡，
必是出自著名工匠之手。西面是一个竹林。
LONG);
	set("exits", ([	     		
		"east":__DIR__"changlang1",
		"west":__DIR__"zhulin",				
	]));

        
       set("valid_startroom", 1);   
       set("outdoors", "青石路");  
	setup();
       
       
}

