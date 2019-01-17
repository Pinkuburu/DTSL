
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", HIM"颂摩崖"NOR);
        set("long", @LONG
颂摩崖又名黄龙碑。周围山势陡峭，两山对峙，一泓中流，两峡旁
有潭，渊深莫测。俗传有黄龙自潭飞出，因名黄龙潭。潭左侧摩崖成碑。
汉隶真迹，笔触遒劲，刀刻有力，记叙了开天井道的过程。往东南是仇
池山，往西则是胭脂山。
LONG);
        set("outdoors", "tuyuhun");

        set("exits", ([
                "eastdown" : __DIR__"silk2",
                "westdown" : __DIR__"silk4",
                "north" : __DIR__"silk3a",
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
   if(strsrch(time,"丑时三刻")==-1
     )
    return notify_fail("你现在什么也领会不出来。\n");
   
   msg="$N静静领会起狂沙刀法，对其中的“吹”字诀有了更深的认识！\n";
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