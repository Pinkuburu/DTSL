
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", GRN"竹林"NOR);
	set("long", @LONG
这里是竹林。碧绿的竹子在微风的吹拂下不住晃动，发出沙沙的声
音。南面是一个庭院。
LONG);
	set("exits", ([	     				
		"south":__DIR__"tingyuan",
		"northeast":__DIR__"zhulin",				
	]));

        
       set("valid_startroom", 1);   
       set("outdoors", "青石路");  
	setup();
       
       
}

