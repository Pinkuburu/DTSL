
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "大路");
	set("long", @LONG
这里是一条宽敞的大路。北边就是杭州的南门了。这里的道路非常
宽敞，四周景色秀丽。不时有大队的官兵从你的身旁走过，领头的将领
不时回头打量着你。
LONG);
	set("exits", ([
		"south":__DIR__"dalu3",
		"north":"/d/hangzhou/nanmen",
		]));
      set("valid_startroom", 1);   
       set("outdoors", "青石路");  
	setup();
       
       
}

