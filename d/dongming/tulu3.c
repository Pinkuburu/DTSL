
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "土路");
	set("long", @LONG
这里是一条土路。再往北边走，就是浙江的境地了。这里的行人渐
渐多了起来。
LONG);
	set("exits", ([
		"south":__DIR__"tulu2",
		"north":__DIR__"dalu1",
		]));
      set("valid_startroom", 1);   
       set("outdoors", "青石路");  
	setup();
       
       
}

