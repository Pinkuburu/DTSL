
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", GRN"练武场"NOR);
	set("long", @LONG
这里是东溟派的练武场。有很多弟子在这里练习武艺。只听吆喝之
上不断传来，刀光剑影，一派热闹的景象。
LONG);
	set("exits", ([
		"north":__DIR__"tingyuxuan",	
		"south":__DIR__"caodi1",		
	]));
	set("objects",([
		__DIR__"npc/shangbang":1,
		]));
     set("valid_startroom", 1);   
       set("outdoors", "青石路");  
	setup();
       
       
}

