
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "仇池山");
        set("long", @LONG
这里绝壁峭峙，孤险云高，山峰拔地而起，直刺蓝天。山顶平田千
亩，风景秀美，物产丰饶，气候温和，泉水多，胜迹遍山。仇池石色赭
红，吸水性能强，适宜养育小树花卉。远远可以看见东南边有一座雄伟
的关隘。
LONG);
        set("outdoors", "tuyuhun");

        set("exits", ([
                "southeast" : __DIR__"silk",
                "north" : __DIR__"silk2",
                "southwest" : __DIR__"silk1a",
        ]));

        setup();
}

void init()
{
  add_action("do_linghui","linghui");

}

int do_linghui()
{
   object ob;
   string time,msg;
   
   ob=this_player();
   
   if(ob->query_skill("kuangsha-daofa",1)<160)
   return 0;
   if(ob->query("perform_quest/kuangsha"))
   return 0;
   if(ob->query_skill("feiwo-whip",1))
   return 0;
   
   time=NATURE_D->game_time();
   if(strsrch(time,"子时三刻")==-1
     )
    return notify_fail("你现在什么也领会不出来。\n");
   
   msg="$N静静领会起狂沙刀法，对其中的“旋”字诀有了更深的认识！\n";
   message_vision(msg,ob);
   ob->set_temp("perform_quest/kuangsha_action1",1);
   if(ob->query_temp("perform_quest/kuangsha_action1")
    &&ob->query_temp("perform_quest/kuangsha_action2")
    &&ob->query_temp("perform_quest/kuangsha_action3")
    &&ob->query_temp("perform_quest/kuangsha_action4")
    &&ob->query_temp("perform_quest/kuangsha_action5")
     ){
    msg="$N微微一笑：狂沙刀法已然有所成就！\n";
    message_vision(msg,ob);
    ob->set("perform_quest/kuangsha",1);
    ob->delete_temp("perform_quest");
   }
   return 1;
}