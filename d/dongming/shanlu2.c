
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "山路");
	set("long", @LONG
这里是条山路。这里几乎没有什么人，一片荒凉萧瑟的气氛。四周
杂草丛生，只有几只野兔不时从你的脚前跑过。再往西走，就要到江西
的境地了。
LONG);
	set("exits", ([
		"southeast":__DIR__"shanlu1",
		"north":__DIR__"shanlu3",
		]));
      set("valid_startroom", 1);   
       set("outdoors", "青石路");  
	setup();
       
       
}

