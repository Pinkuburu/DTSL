
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "山路");
	set("long", @LONG
这里是一条山路。再往西北走，就是江西的境地了。这里嫣红姹紫，
遍山遍野都是鲜花，春光浪漫已极。
LONG);
	set("exits", ([
		"southeast":__DIR__"tulu1",
		"northwest":__DIR__"shanlu6",
		]));
      set("valid_startroom", 1);   
       set("outdoors", "青石路");  
	setup();
       
       
}

