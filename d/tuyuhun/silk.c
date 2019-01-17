// /d/xingxiu/silk.c

inherit ROOM;

void create()
{
        set("short", "丝绸之路");
        set("long", @LONG
这是闻名中外的丝绸商道。迎面而来的是一个个沙包，星罗棋布於
荒原之上。一阵风沙吹过，象刀割一样撕裂着你的脸。东边有一座雄伟
的关隘，西面则通往西域。
LONG);
        set("outdoors", "tuyuhun");

        set("exits", ([
                "east" : "/d/taiyuan/jiayuguan",
                "northwest" : __DIR__"silk1",
                "southwest" : __DIR__"silk1b",
                "southeast" : __DIR__"silk11",
        ]));

        set("objects", ([
                __DIR__"npc/shangren" : 1,
        ]));

        setup();
}

