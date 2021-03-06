
inherit F_MASTER;
inherit NPC;

#include <ansi.h>

void create()
{
   set_name("边不负",({ "bian bufu","bian","bu","fu" }) );
   set("gender", "男性" );
   set("nickname","魔隐");
   set("age", 42);
   set("long", "他是阴癸派的高手之一，他的武功仅次于祝玉妍。\n");
       
   set("combat_exp",600000);
   set_skill("dodge",150);
   set_skill("parry",150);
   set_skill("force",150);
   set_skill("strike",150);
   set_skill("jiutian-huanzhang",150);
   set_skill("moxin-lianhuan",150);
   set_skill("literate",150);
   set_skill("tianmo-dafa",150);
   set_skill("tianmo-jue",150);
   set_skill("tianmo-huanzong",150);
   
   set("max_gin",2000);
   set("max_kee",2000);
   set("max_sen",2000);
   set("force",2000);
   set("max_force",2000);
   create_family("阴癸派",5,"长老");
   setup();
  
}
void attempt_apprentice(object ob)
{
	
	if(ob->query("family"))
	if(ob->query("family/family_name")=="阴癸派")
	if((int)ob->query("family/generation",1)<=5)
	{   
	   command("say 此话从何说起？\n");
	   return;
	}
	if(ob->query("gender")=="女性"){
	
	command("say 我不收女弟子的！你如果诚心投入本派，去找旦梅吧！\n");
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

	command("say 好！希望你将来能一统魔道，长我阴癸派名声！\n");
	command("recruit "+ob->query("id"));
	return;
}

int recruit_apprentice(object ob)
{
   if( ::recruit_apprentice(ob) )
     ob->set("class", "yin2");
}

int end_fight(object killer,object victim)
{
    if(!victim->query_temp("perform_quest/duomeng_action1"))
    return 1;
    victim->add_temp("perform_quest/duomeng_wins",1);
    return 1;
}

int surrender(object killer,object victim)
{
   string msg;
   
   if(!killer->query_temp("perform_quest/duomeng_action1"))
   return 1;
   if(killer->query_temp("perform_quest/duomeng_wins")!=2)
   return 1;
   
   msg="$N朝$n冷笑一声：果然长江后浪推前浪！既然你已经晓得我和东溟派的恩怨，\n"+
       "那么就下手吧！\n";
   msg+="\n$n想到上一代武林的恩恩怨怨，善恶因果，均何自己这一代人没有任何关系。\n"+
        "飘梦剑法也是意在梦幻虚无，过去的一切也只不过是梦幻而已。\n";
   message_vision(msg,victim,killer);
   killer->delete_temp("perform_quest/duomeng_action1");
   killer->delete_temp("perform_quest/duomeng_wins");
   killer->set("perform_quest/duomeng",1);
   return 1;
}