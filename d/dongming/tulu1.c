
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "土路");
	set("long", @LONG
这里是一条土路。从这里可以去江西和浙江。这里没有什么行人。
四周杂草丛生，只有几只野兔不时从你的脚前跑过。旁边有几棵大树，
树枝已经凋零，上面零散地落着几只乌鸦，朝着天空哑哑地叫着。
LONG);
	set("exits", ([
		"south":__DIR__"chaguan",
		"northwest":__DIR__"shanlu5",
		"northeast":__DIR__"tulu2",
		]));
      set("valid_startroom", 1);   
       set("outdoors", "青石路");  
	setup();
       
       
}

