// /d/xingxiu/silk10.c

inherit ROOM;

//string do_joke();

void create()
{
        set("short", "丝绸之路");
        set("long", @LONG
这是闻名中外的丝绸商道。风沙弥漫，一片荒凉景象。这儿常有盗
匪出没。西北通向一片连绵的山脉，东面就是通向中原的路。路边有一
块石碑(shibei)。
LONG );
       set("outdoors", "yili");

        set("exits", ([
                "southeast" : __DIR__"silk8",
                "west" : __DIR__"shamo1",
                "northwest" : __DIR__"shanjiao",
        ]));
        
        set("item_desc",([
         "shibei":"明年的今日，此地将是"+this_player()->name()+"的葬身之地！\n\n",
         ]));

        setup();
}
