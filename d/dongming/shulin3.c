
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", GRN"树林"NOR);
	set("long", @LONG
这里是片树林。这里几乎没有什么人。这里偶尔可以听到几声清脆
的鸟鸣声。
LONG);
	set("exits", ([
		"west":__DIR__"shulin1",
		]));
        set("objects",([
          __DIR__"npc/shangming":1,
          ]));
        
       set("valid_startroom", 1);   
       set("outdoors", "青石路");  
	setup();
       
       
}

