
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "山路");
	set("long", @LONG
这里是条山路。这里的行人渐渐多了起来，有很多武林人士从你身
旁走过。
LONG);
	set("exits", ([
		"southeast":__DIR__"shanlu3",
		"northwest":"/d/jiujiang/tulu2",
		]));
      set("valid_startroom", 1);   
       set("outdoors", "青石路");  
	setup();
       
       
}

