
inherit ROOM;

void create()
{
        set("short", "万象洞");
        set("long", @LONG
这是一个深邃的洞穴，洞内钟乳石绚丽多姿，美妙神奇。有犀牛望
月、五岳朝天、卧龙坪、炼丹井、仙人灶、上天梯、独木桥等，景象万
千，耐人寻味。一直沿着洞向西走，就能到月牙泉了。
LONG);
        set("outdoors", "tuyuhun");

        set("exits", ([
                "eastup" : __DIR__"silk3a",
                "west" : __DIR__"silk3c",
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
   if(strsrch(time,"辰时三刻")==-1
     )
    return notify_fail("你现在什么也领会不出来。\n");
   
   msg="$N静静领会起狂沙刀法，对其中的“破”字诀有了更深的认识！\n";
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