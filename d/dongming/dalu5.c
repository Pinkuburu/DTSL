
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "大路");
	set("long", @LONG
这里是一条大路。北边可以遥遥望见九江的城门了。这里虽然地处
偏僻，但这里来往的行人仍然很多。
LONG);
	set("exits", ([
		"south":__DIR__"shanlu6",
		"north":__DIR__"dalu6",
		]));
      set("valid_startroom", 1);   
       set("outdoors", "青石路");  
	setup();
       
       
}

