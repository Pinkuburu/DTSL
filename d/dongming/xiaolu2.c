
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "小路");
	set("long", @LONG
这里是一条小路。这里几乎没有什么人来。一阵风吹过，卷起阵阵
狂沙。
LONG);
	set("exits", ([
		"southeast":"/d/wuyishan/shanjiao",
		"northwest":__DIR__"shalu1",
		]));
      set("valid_startroom", 1);   
       set("outdoors", "青石路");  
	setup();
       
       
}

