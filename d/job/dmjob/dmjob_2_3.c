/*
 * File    : 观日台 (/u/yanyan/dmjob/dmjob_2_3.c)
 * Author  : [1;37m真冰河[2;37;0m(yanyan@大唐双龙  )
 * Date    : Thu Oct 18 11:38:33 2001
 */
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "观日台");
        set("long", @LONG
这里是屏风山的观日台了。这里地势非常高，所以是早晨观赏的日
出的极佳之地。这里和屏风山飞天岭遥遥相望。白云笼罩着这里，形成
了一种奇异的气氛。
LONG
);
        set("exits",([
	"southdown" : __DIR__"dmjob_4_3",
        ]));
set("outdoors","dmjob");
        setup();
//        replace_program(ROOM);
}
