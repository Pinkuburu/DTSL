
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", GRN"花园"NOR);
	set("long", @LONG
这里是座花园。这里很多奇花异草，品种繁多，看起来美不胜收。
南边有一片树林。北边是一条小径。
LONG);
	set("exits", ([
		"south":__DIR__"shulin1",
		"north":__DIR__"xiaojing2",
		
	]));
   set("objects",([
	   __DIR__"npc/shanxiu":1,
	   ]));
        
       set("valid_startroom", 1);   
       set("outdoors", "青石路");  
	setup();
       
       
}

