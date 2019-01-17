// /d/xingxiu/silk7.c
inherit ROOM;

void create()
{
        set("short", "敦煌");
        set("long", @LONG
这里是敦煌城所在地，是丝绸之路上的咽喉重镇。四面城墙高耸，
另有高出城墙一倍的城墩。城内混居了周围的多个民族，走在大街上看
到和听到的无不透着新奇。
LONG);
        set("outdoors", "tuyuhun");

        set("exits", ([
                "southeast" : __DIR__"silk6",
                "west" : __DIR__"silk8",
                "southdown" : __DIR__"silk7a",
        ]));

        setup();
}

