// Room: /d/hengshan/sanjiaodian.c
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "三教殿");
        set("long", @LONG
这里是全寺最高处的三教殿，也是悬空寺最大的殿宇。三层九脊，
全部由每根插入崖石的木梁承受，真是 "公输天巧"， 古今奇迹。
LONG);
        set("exits", ([ 
           "down"   : __DIR__"xuankong1",
        ]));
        setup();
        replace_program(ROOM);
}
