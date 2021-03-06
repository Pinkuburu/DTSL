
inherit NPC;

#include <ansi.h>

string do_quest1();

void create()
{
   set_name("洪小裳",({ "hong xiaoshang","hong","xiaoshang" }) );
        set("gender", "女性" );
		
        set("age", 23);
   set("long", "她是阴癸派的弟子，准备密谋逃出阴癸派。\n");
   set("per",20);
   set("combat_exp",300000);
  
   set_skill("dodge",100);
   set_skill("parry",100);
   set_skill("force",100);
   set_skill("strike",100);
   set_skill("cuff",100);
   set_skill("sword",100);
   
   set_skill("jiutian-huanzhang",100);
   set_skill("literate",100);
   set_skill("tianmo-dafa",100);
   set_skill("tianmo-huanzong",100);
   set_skill("linglong-yuquan",100);
  
   set("max_gin",1000);
   set("max_kee",1000);
   set("max_sen",1000);
   set("force",1000);
   set("max_force",1000);
   create_family("阴癸派",7,"弟子");
   set("inquiry",([
   "天魔阵":(:do_quest1:),
   ]));
   setup();
   
}

string do_quest1()
{
  object ob,*man,target;
  
  ob=this_player();
  
  if(ob->query("dtsl_quest_yinguifinal"))
  return "凭你的功夫学习天魔阵太可惜了！\n";
  
  if(!ob->query_temp("tmz_quest/pass_xia")
    ||!ob->query_temp("tmz_quest/pass_yun")
    ||!ob->query_temp("tmz_quest/pass_wen")
    )
  return "你的功夫太差劲了，怎么学习「天魔阵」啊！\n";
  
  ob->set_temp("tmz_quest/hong_step1",1);
  
  man=children(__DIR__"hanzenan");
  if(sizeof(man)<2){
    target=new(__DIR__"hanzenan");
    target->move(environment(ob));
    tell_object(environment(ob),target->name()+"走了过来。\n");
    set("couple_ob",target);
  }
  
  return "你已经发现了我的行踪！如果你不告诉他人，\n"+
         "作为回报，我会给你载有「天魔阵」的书籍！\n";
}

int accept_object(object ob,object obj)
{
   if(!obj->query("quest_hong"))
    return 0;
   
   ob->delete_temp("tmz_quest");
   ob->set("dtsl_quest_tmz",1);
   message_vision("$N朝$n深拘一躬：谢谢你放我们一条生路！\n"+
                  "我马上给你载有「天魔阵」的书籍。\n",
                  this_object(),ob);
   call_out("do_kill",1,ob);
   return 1;
}

void do_kill(object ob)
{
   object target,book;
   string msg;
   
   if(!ob) return;
   
   target=query("couple_ob");
   book=new(__DIR__"obj/tmz_book");
   
   msg="\n$N突然冷笑道：不必了！我自己会拿的！！\n"+
       "$N突然面露凶光，突然朝$n下了杀手！\n\n"+
       HIR+"只见$n胸口溅起了一道血光！！\n"NOR;
   message_vision(msg,ob,this_object());
    if(target){
      msg="\n$N凶光扫到$n身上，\n"+HIR+"只见$n胸口溅起了一道血光！！\n"NOR;
      message_vision(msg,ob,target);
    }
   if(target)
    target->die();
   book->move(ob);
   tell_object(ob,"你从"+query("name")+"身上拿到了一"+book->query("unit")+
        book->query("name")+"。\n");
   message("vision",HIM"【谣言】某人：正在逃亡的洪小裳和韩泽南被"+ob->name()+HIM+
    "杀害了！\n"NOR,users());
   die();
}