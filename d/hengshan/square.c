// Room: /d/hengshan/huixiantai.c
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "见性峰");
        set("long", @LONG
这里是恒山主峰见性峰峰顶。在这里俯瞰群山，才理会得何以恒山
是华夏北方万山之宗。
LONG);
        set("exits", ([
           "westdown"  : __DIR__"shandao2",
        ]));
        set("outdoors", "hengshan");
        setup();
        replace_program(ROOM);
}

