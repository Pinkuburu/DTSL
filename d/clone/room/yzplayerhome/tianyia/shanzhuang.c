
inherit ROOM;
#include <ansi.h>
void create()	
{
	set("short","弈花山庄");
	set("long", @LONG
这里是弈花山庄了 。这里的主人是添翼(tianyia)和小燕姿
(yanzi) 夫妇。只见这里摆着一张方桌，放着几个凳子，桌子上
还有一壶刚刚沏好的茶水。正面是两把太师椅。正上方的墙壁上
挂着一把剑，上面刻着“轻舞飞扬”四个字。北面是一间厨房，
南面是一间院子，楼上则是主人夫妇休息的卧室。
LONG);
    set("exits", ([
	        "up" : __DIR__"woshi",
	        "south":__DIR__"door",
	        "north":__DIR__"chufang",
 	]));
      set("no_fight",1);
      setup();
      replace_program(ROOM);
	
}
