// /d/gaoli/xuanwumen
// Room in 高丽
#include <ansi.h>
inherit ROOM;

#define FROM __DIR__"jiangnan"
#define	TO	__DIR__"jiangbei"
#define SHIPDIR __DIR__"duchuan2"

#include "/std/shiproom.c";

void create()

{
set("short", "鸭绿江南岸");

	set("long", @LONG
这里是鸭绿江的南岸。从这里乘船北上，就可以到中原的北方了。
这里停泊着几艘小船，看远处还有小船要靠近岸来。你可以叫船家(yell 
boat)来乘船。
LONG
	);
	

set("outdoors", "/d/gaoli");
set("exits", ([
		"south" : __DIR__"milin1",
		               
	]));
       setup();
	
}
