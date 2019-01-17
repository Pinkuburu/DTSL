// /d/xingxiu/silk.c

inherit ROOM;

void create()
{
        set("short", "丝绸之路");
        set("long", @LONG
这是闻名中外的丝绸商道。扑面的风沙隐隐送来了远处的驼铃声，
荒原之上，不时能看到一片片戈壁滩，很少能见到飞禽走兽，南边是天
水城，北边则进入了石门地区。
LONG);
        set("outdoors", "tuyuhun");

        set("exits", ([
                "northwest" : __DIR__"silk5",
                "south" : __DIR__"tianshui",
        ]));
        set("valid_startroom", 1);
        setup();
}

