
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", GRN"海滩"NOR);
	set("long", @LONG
这里是海滩。不时有巨浪冲上岸来。北边有一个码头。海风吹得你
衣衫凌乱。
LONG);
	set("exits", ([
		"southwest":__DIR__"xiaojing1",
		"north":__DIR__"gangkou",
		"east":__DIR__"haitan2",
		"west":__DIR__"haitan3",
		
	]));
      set("valid_startroom", 1);   
       set("outdoors", "青石路");  
	setup();
       
       
}

