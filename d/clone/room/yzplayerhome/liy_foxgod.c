
inherit ROOM;
#include <ansi.h>
void create()	
{
	set("short",HIW"醉剑居"NOR);
	set("long", @LONG
这里是醉剑居了。这里的男女主人是一风（LIY）和天外神龙
（FOXGOD）。两个人在武林中都算是高手之列。只见这里摆着一
张方桌，放着几个凳子，桌子上还有一壶刚刚沏好的茶水。正面
是两把太师椅，中间挂着一张观音菩萨像。北边是一间卧室。
LONG);
    set("exits", ([
	        "west" : __DIR__"nandajie1",
	        "north":__DIR__"liy_foxgod_woshi",
 	]));
      set("no_fight",1);
      setup();
      replace_program(ROOM);
	
}
