
inherit ROOM;
#include <ansi.h>
void create()	
{
	set("short",HIC"刀剑居"NOR);
	set("long", @LONG
这里是刀剑居了。这里的男女主人是子陵(sap)和龙神(wlq)。
两个人在武林中都算是高手之列。只见这里摆着一张方桌，放着
几个凳子，桌子上还有一壶刚刚沏好的茶水。正面是两把太师椅，
中间挂着一张观音菩萨像。北边是一间卧室。
LONG);
    set("exits", ([
	        "west" : __DIR__"nandajie3",
	        "north":__DIR__"sap_wlq_woshi",
	        "up":__DIR__"up_wlq_sap",
 	]));
      set("no_fight",1);
      setup();
      replace_program(ROOM);
	
}
