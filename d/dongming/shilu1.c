
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", GRN"青石路"NOR);
	set("long", @LONG
这里是青石路，地上铺着整齐的方砖。前面是一个花园。东西两面
各有一个房间。
LONG);
	set("exits", ([
	     
		"south" :__DIR__"huayuan",
		"north":__DIR__"shijie3",
		"east":__DIR__"xiangfang",
		"west":__DIR__"muwu1",
		
	]));

 set("objects",([ "/d/job/dmshouzhang/zhangfang":1,]));
        
       set("valid_startroom", 1);   
       set("outdoors", "青石路");  
	setup();
       
       
}

