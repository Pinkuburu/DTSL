// /d/xingxiu/silk6.c

inherit ROOM;

void create()
{
        set("short", "丝绸之路");
        set("long", @LONG
这是闻名中外的丝绸商道。风沙弥漫，一片荒凉景象。南面连绵的
祁连山脉在阳光的照射下好像是一条玉带。只是有几人合抱之粗的古老
胡杨，仍然挺立在荒原上，笑迎风沙，频频招呼行人。西南是一片黄沙，
传过沙漠就可以到达昆仑山脉。
LONG);
        set("outdoors", "tuyuhun");

        set("exits", ([
              "southeast" : __DIR__"silk3a",
              "northwest" : __DIR__"silk7",
        ]));

        set("objects", ([
                __DIR__"npc/shangren" : 1,
        ]));

        setup();
}

