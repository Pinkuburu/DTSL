
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", GRN"大院"NOR);
	set("long", @LONG
这里是一个大院。这里是东溟平时休息聊天的地方。很多弟子在这
里谈天说地。南边就是东溟的青竹宫了，是东溟派的掌门所居住的地方。
LONG);
	set("exits", ([
	     
		
		"north":__DIR__"baiyuanshi",
		"south":__DIR__"qingzhugong",
		
	]));
   set("objects",([
	   __DIR__"npc/shangkuitai":1,
	   ]));
       set("valid_startroom", 1);   
       set("outdoors", "青石路");  
	setup();
       
       
}

