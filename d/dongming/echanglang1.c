
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", GRN"东廊"NOR);
	set("long", @LONG
这里是东廊。墙壁上刻着一些图画。看起来好像是两个人在西湖中
划船，画工精美，一看就是出自名工匠之手。你不禁被美丽的画面所吸
引。
LONG);
	set("exits", ([	     		
		"east":__DIR__"echanglang2",
		"west":__DIR__"changlang1",
		"north":__DIR__"dawuzi",
		
	]));

        
       set("valid_startroom", 1);   
       set("outdoors", "青石路");  
	setup();
       
       
}

