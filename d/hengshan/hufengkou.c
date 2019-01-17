// Room: /d/hengshan/hufengkou.c
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "虎风口");
        set("long", @LONG
过 "步云桥" ， "望仙亭" ，就到了一个峰回路转的陡峭路口，这
里是一处风口，大风来处，声如虎啸，比别处强劲多多，故有是名。
LONG);
        set("exits", ([ 
           "southwest" : __DIR__"daziling",
           "west"      : __DIR__"xuangengsong",
           "northeast" : __DIR__"guolaoling",
        ]));
        set("outdoors", "hengshan");
        setup();
        replace_program(ROOM);
}

