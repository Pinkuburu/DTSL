
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "山路");
	set("long", @LONG
这里是条山路。据说这条路上经常有强人出没，你不禁加快了脚步。
四周杂草丛生，只有几只野兔不时从你的脚前跑过。
LONG);
	set("exits", ([
		"southeast":__DIR__"chaguan",
		"northwest":__DIR__"shanlu2",
		]));
      set("valid_startroom", 1);   
       set("outdoors", "青石路");  
	setup();
       
       
}

