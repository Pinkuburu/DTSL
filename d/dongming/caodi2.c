
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", GRN"草地"NOR);
	set("long", @LONG
这里是一片草地。南面是东溟的听雨轩。北面是个石阶。有几名子
弟从你的身旁匆匆走过，朝北边的石阶走去。
LONG);
	set("exits", ([
	     
		
		"northup":__DIR__"shijie4",
	
		"south":__DIR__"tingyuxuan",
		
		
	]));
      set("valid_startroom", 1);   
       set("outdoors", "青石路");  
	setup();
       
       
}

