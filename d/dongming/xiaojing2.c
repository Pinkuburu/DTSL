
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", GRN"小径"NOR);
	set("long", @LONG
这里是条小径。这里离海边不远了。南边有一个花园。这里可以听
到大海波涛的声音。
LONG);
	set("exits", ([
		"south":__DIR__"huayuan1",
		"northeast":__DIR__"xiaojing1",
		
	]));
      set("valid_startroom", 1);   
       set("outdoors", "青石路");  
	setup();
       
       
}

