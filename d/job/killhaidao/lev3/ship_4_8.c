/*
 * File    : 水手休息室 (/d/job/killhaidao/lev3/ship_4_8.c)
 * Author  : [1;36m真冰河[2;37;0m(yanyan@大唐双龙  )
 * Date    : Mon Mar 17 21:18:20 2003
 */
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "水手休息室");
        set("long", @LONG
这里是供船上水手休息的场所，里面干干净净。地面上一排排的摆
了许多铺盖。卧室里静悄悄的，正有几个水手躺在铺盖上蒙头大睡。
LONG
);
        set("exits",([
	"north" : __DIR__"ship_2_8",
        ]));
        setup();
//        replace_program(ROOM);
}
