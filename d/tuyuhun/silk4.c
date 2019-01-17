// /d/xingxiu/silk4.c

inherit ROOM;

void create()
{
        set("short", "丝绸之路");
        set("long", @LONG
这是闻名中外的丝绸商道。迎面而来的是一个个沙包，星罗棋布於
荒原之上。一阵风沙吹过，象刀割一样撕裂着你的脸。东边是颂摩崖，
继续往东走便是。
LONG);
        set("outdoors", "tuyuhun");

        set("exits", ([
                "eastup" : __DIR__"silk3",
                "westup" : __DIR__"silk5a",
                
        ]));

        set("objects", ([
                __DIR__"npc/shangren" : 1,
        ]));

        setup();
}

