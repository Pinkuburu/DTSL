
inherit ROOM;
#include <ansi.h>
void create()	
{
	set("short",HIC"沁心冷香居"NOR);
	set("long", @LONG
这是武林绝顶高手“摘星手”皇夜歌 (Strong) 和他娇柔爱
妻苍月草(cougar)爱的小屋。苍月草是当今武林第一美女曾经倾
倒无数武林英豪。只见这里摆着一张方桌，放着几个凳子，桌子
上还有一壶刚刚沏好的茶水。正面是两把太师椅，中间挂着一张
观音菩萨像。北边是一间卧室。
LONG);
    set("exits", ([
	        "east" : __DIR__"nandajie3",
	        "north":__DIR__"strong_cougar_woshi",
 	]));
    set("objects",([
       __DIR__"obj/lanxindie":1,
       ]));
      set("no_fight",1);
      setup();
      replace_program(ROOM);
	
}
