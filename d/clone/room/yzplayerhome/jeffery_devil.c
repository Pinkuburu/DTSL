
inherit ROOM;
#include <ansi.h>
void create()	
{
	set("short",HIC"逍遥居"NOR);
	set("long", @LONG
这里是逍遥居了。这里的男女主人是破晓(jefferry)和悠悠
(devil) 两个人在武林中都算是高手之列。只见这里摆着一张方
桌，放着几个凳子，桌子上还有一壶刚刚沏好的茶水。正面是两
把太师椅，中间挂着一张观音菩萨像。北边是一间卧室。
LONG);
    set("exits", ([
	        "west" : __DIR__"nandajie2",
	        "north":__DIR__"jeffery_devil_woshi",
 	]));
      set("no_fight",1);
      setup();
      replace_program(ROOM);
	
}
