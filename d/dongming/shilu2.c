
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", GRN"青石路"NOR);
	set("long", @LONG
这里是青石路。地上铺着整齐的方砖。后面是一个花园。东边有一
个木屋。再往前走就是一个长廊了。
LONG);
	set("exits", ([
	     
		"north" :__DIR__"huayuan",
		"south":__DIR__"changlang1",
		"east":__DIR__"muwu3",
		
		
	]));

        
       set("valid_startroom", 1);   
       set("outdoors", "青石路");  
	setup();
       
       
}

