
inherit ROOM;
#include <ansi.h>
void create()	
{
	set("short",YEL"楼阁"NOR);
	set("long", @LONG
这里是一个楼阁，下面是龙神和子陵的房间了。从这里可以
看到远处扬州的风景，非常热闹。楼阁旁边还放着几盆鲜花，品
种繁多。
LONG);
    set("exits", ([
	        "down":__DIR__"wlq_sap",
 	]));
      set("no_fight",1);
      setup();
      replace_program(ROOM);
	
}
