// /d/xingxiu/silk5.c
inherit ROOM;

void create()
{
        set("short", "兴隆山");
        set("long", @LONG
此山东西两面山坡上，天然林密布，有云杉、松、桦、柳、杨等乔
木及灌木丛。峰峦叠翠，四季长青。上有太白、玉液泉，汇成小溪山涧，
清流潺潺。中有大峡河，清澈见底，南北穿越峡谷。地阴潮湿，气温较
低，为游览避暑胜地。
LONG);
        set("outdoors", "tuyuhun");

        set("exits", ([
                "north" : __DIR__"silk5",
        ]));

       /* set("objects", ([
                __DIR__"npc/muren" : 2,
        ]));*/

        setup();
        replace_program(ROOM);
}
