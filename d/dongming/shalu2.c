
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "沙路");
	set("long", @LONG
这里是一条沙路。由于连年的战乱，这里几乎没有什么行人，一片
荒凉萧瑟的气氛。四周杂草丛生，只有几只野兔不时从你的脚前跑过。
LONG);
	set("exits", ([
		"south":__DIR__"shalu1",
		"northwest":__DIR__"chaguan",
		]));
      set("valid_startroom", 1);   
       set("outdoors", "青石路");  
	setup();
       
       
}

