
inherit F_MASTER;
inherit NPC;

#include <ansi.h>

void create()
{
   set_name("白清儿",({ "bai qinger","bai" }) );
        set("gender", "女性" );
        set("age", 23);
        set("per",26);
   set("long", "她是钱独关最宠爱的小妾，也是阴癸派新\n"+
               "一代的年轻高手。\n");
       
   set("combat_exp",600000);
   set_skill("dodge",150);
   set_skill("parry",150);
   set_skill("force",150);
   set_skill("cuff",150);
   set_skill("linglong-yuquan",150);
   set_skill("literate",150);
   set_skill("tianmo-dafa",150);
   set_skill("tianmo-jue",150);
   set_skill("tianmo-huanzong",150);
   
   set("max_gin",2000);
   set("max_kee",2000);
   set("max_sen",2000);
   set("force",2000);
   set("max_force",2000);
   create_family("阴癸派",5,"弟子");
   setup();
  
}
void attempt_apprentice(object ob)
{
	int lev;
	
	if(ob->query("family"))
	if(ob->query("family/family_name")=="阴癸派")
	if((int)ob->query("family/generation",1)<=5)
	{   
	   command("say 此话从何说起？\n");
	   return;
	}
	if(ob->query("gender")=="男性"){
	
	command("say 我不收男弟子的！你如果诚心投入本派，去找林士宏吧！\n");
	return;
        }
        if(ob->query_skill("tianmo-dafa",1)<100){
        command("say 你的天魔大法修为不够，还是再去修习一下再拜我为师吧！\n");
        return;
        }
        
        if(ob->query("class")!="yin1"){
          command("say 你没有“斩俗缘”，我如何收你为徒！");
          return;
        }
        
        if(ob->query("office_number")<30){
        command("say 你的功绩这么低，我可不要这么懒惰的弟子！\n");
        return;
        }
        if(ob->query_per()<25){
	 command("hmm1");
	 command("say 你的样子不够漂亮，我可不收这样的弟子！\n");
	 return;
	}
	
	lev=ob->query_skill("sword",1);
        lev=lev*lev/(lev+100);
        ob->party_reward_skill("cuff",lev);
        tell_object(ob,HIY"你从基本剑法中领略到了基本拳法！\n"NOR);       
	command("say 好！希望你将来能一统魔道，长我阴癸派名声！\n");
	command("recruit "+ob->query("id"));
	return;
}

int recruit_apprentice(object ob)
{
   if( ::recruit_apprentice(ob) )
     ob->set("class", "yin2");
}

