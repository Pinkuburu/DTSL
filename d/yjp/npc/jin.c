// 大唐双龙传

inherit F_MASTER;
inherit NPC;

#include <ansi.h>

int do_action1();

void create()
{
  set_name("金正宗", ({"jin zhengzong", "jin", "zhengzong"}));
  set("gender", "男性");
  set("age", 38);
  set("str",30);
  set("per",23);
  set("max_kee",3000);
  set("max_gin",3000);
  set("max_sen",3000);
  set("max_force",3000);
  set("force",3000);
  set("combat_exp",800000);
  set_skill("unarmed",200);
  set_skill("strike",200);
  set_skill("leg",200);
  set_skill("literate",200);
  set_skill("sword",200);
  set_skill("force",200);
  set_skill("dodge",200);
  set_skill("parry",200);
  set_skill("whip",200);
  set_skill("blade",200);
  set_skill("cuff",200);
  set_skill("finger",200);
  set("inquiry",([
  "俸禄":(:do_action1:),
  ]));
  setup();
  
  create_family("弈剑派", 6, "弟子");
 
}
void attempt_apprentice(object ob)
{
     
     if(!ob->query_temp("bai_yjp_action4")){
       command("say 我可不是轻易收弟子的！");
       return;
     }
    
     ob->set("yjp/family1",1);
     
     command("say 各种武功我都会一些，你就在我这里学点基本功夫吧！");
     
     command("recruit " + ob->query("id") );
}
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "gaoli1");
}

int do_action1()
{
   object ob;
   int money;
   
   
   ob=this_player();
   
   if(ob->query_skill("jiuxuan-dafa",1)<100){
   	command("say 你的功夫这么差劲，还想来领俸禄？");
   	return 1;
   }
   if(ob->query("yjp/fenglu_age_"+ob->query("age"))){
     command("say 你今年的俸禄已经领完了！");
     return 1;
   }
   ob->set("yjp/fenglu_age_"+ob->query("age"),1);
   money=ob->query("office_number")*100;
   ob->add("deposit",money);
   command("say 好，你今天的俸禄是"+MONEY_D->money_str(money)+"，我已经存到了你钱庄中！");
   return 1;
}