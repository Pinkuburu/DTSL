
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", GRN"大屋"NOR);
	set("long", @LONG
这里是一个宽敞的大屋子。这里是东溟管家做事的地方。正面放着
一张大桌子，上面放了很多账本等东西。东溟管家正在那里办事。这里
的摆设很简单，没什么豪华的东西。
LONG);
	set("exits", ([	     		
		"south":__DIR__"echanglang1",
		
	]));
/*       set("objects",([
          "/d/job/dmjob/guanjia":1,
          ]));*/
       set("no_fight",1);
       set("valid_startroom", 1);   
    	setup();
       
       
}

