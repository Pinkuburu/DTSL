

inherit ROOM;

void create ()
{
        set ("short", "明堂窝");
        set ("long", @LONG
这里是长安有名的赌场，主持人是江湖闻名的大仙胡佛，据说
此人的赌技已经到了出神入化的地步。明堂窝的四个贵宾堂是四座
独立的建筑物，以游廊把主堂相连起来，游廊两旁是亭池园林的美
景，环境清雅，与主堂的喧哗热闹大异其趣。
LONG);

        set("exits", 
        ([
     "east" : __DIR__"yadajie2",
        ]));
        set("objects",([
         "/obj/mj":1,
         ]));
        setup();
   replace_program(ROOM);
}


