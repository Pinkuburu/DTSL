
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", GRN"小径"NOR);
	set("long", @LONG
这里是条小径。北边就是海滩了。你四处看了看，似乎远处有一个
巨大的建筑物。
LONG);
	set("exits", ([
		"southwest":__DIR__"xiaojing2",
		"northeast":__DIR__"haitan1",
		
	]));
	set("objects",([
          __DIR__"npc/shanggong":1,
          ]));
      set("valid_startroom", 1);   
       set("outdoors", "青石路");  
	setup();
       
       
}

