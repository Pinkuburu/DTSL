// /d/gaoli/xuanwumen
// Room in 高丽
#include <ansi.h>
inherit ROOM;

#define FROM __DIR__"jiangbei"
#define	TO	__DIR__"jiangnan"
#define SHIPDIR __DIR__"duchuan2"

#include "/std/shiproom.c";


void create()

{
set("short", "鸭绿江北岸");

	set("long", @LONG
这里是鸭绿江的北岸。从这里乘船南下，就可以到高丽了。这里的
人比较多，这里停泊着几艘小船，看远处还有小船要靠近岸来。你可以
叫船家(yell boat)来乘船。
LONG
	);
	

set("outdoors", "/d/gaoli");
set("exits", ([
		"north" : "/d/yangzhoubei/tulu",
		               
	]));
       setup();
	
}
