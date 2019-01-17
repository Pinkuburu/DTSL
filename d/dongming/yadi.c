
inherit ROOM;
#include <ansi.h>
int do_pa();
void create()
{
	set("short", HIB"山崖底"NOR);
	set("long", @LONG
这里是山崖的底部。这里看起来有些荒凉，杂草丛生。你仔细一看，
发现四周有很多的死尸，看来是从上面摔下来死的。
LONG);
	set("exits", ([
		"up":__DIR__"shanya2",
	
	]));
 if(sizeof(children(__DIR__"obj/zhanlangdao"))<2)
	set("objects",([
		__DIR__"obj/zhanlangdao":1,
		]));
set("no_clean_up",1);
      set("valid_startroom", 1);   
       set("outdoors", "yadi");  
	setup();
       
       
}

int valid_leave(object me,string dir)
{
	if(dir=="up"&&me->query("sen",1)<300)
		return notify_fail("你沮丧地发现凭现在的精神根本爬不上如此高的悬崖。\n");
	me->receive_damage("sen",300);
	return ::valid_leave(me,dir);
}

