
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "茶馆");
	set("long", @LONG
这里是一个废弃的茶馆。本来是招待来往的行人，但是由于战乱，
这家茶馆已经没有人经营了。
LONG);
	set("exits", ([
		"southeast":__DIR__"shalu2",
		"northwest":__DIR__"shanlu1",
		"north":__DIR__"tulu1",
		"east":"/d/haisha/cunxi",
		]));
		/*
	set("objects",([
		__DIR__"npc/shangren":1,
		]));
		*/
      set("valid_startroom", 1);   
       set("outdoors", "青石路");  
	setup();
       
       
}

