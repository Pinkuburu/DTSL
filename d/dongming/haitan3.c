
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", GRN"海滩"NOR);
	set("long", @LONG
这里是海滩。一阵海风吹来，你的衣衫不禁有些凌乱了。南边有一
个悬崖，平时很少有人去那里。
LONG);
	set("exits", ([
		"southwest":__DIR__"shanya2",
		"east":__DIR__"haitan1",
	]));
	set("objects",([
	   __DIR__"obj/yezishu":1,
	   ]));
      set("valid_startroom", 1);   
       set("outdoors", "青石路");  
	setup();
       
       
}

