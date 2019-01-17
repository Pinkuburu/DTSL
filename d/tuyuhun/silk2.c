inherit ROOM;

void create()
{
        set("short", "丝绸之路");
        set("long", @LONG
这是闻名中外的丝绸商道。迎面而来的是一个个沙包，星罗棋布於
荒原之上。一阵风沙吹过，象刀割一样撕裂着你的脸。南面过仇池
山通往嘉峪关，西面则是颂摩崖。
LONG);
        set("outdoors", "tuyuhun");

        set("exits", ([
                "westup" : __DIR__"silk3",
                "south" : __DIR__"silk1",
        ]));

     /*   set("objects", ([
                __DIR__"npc/shangren" : 1,
        ]));*/

        setup();
}

