
inherit F_MASTER;
inherit NPC;
#include <ansi.h>

void create()
{
   set_name("单玉蝶",({ "shan yudie","shan","yudie" }) );
   set("gender", "女性" );
   set("nickname","护法仙子");
   set("age", 24);
   set("long", "这是东溟派的四大护法仙子之一。\n");
       
   set("combat_exp",600000);
   set("per", 25);
   set_skill("dodge",150);
   set_skill("parry",150);
   set_skill("force",150);
   set_skill("whip",150);
  
   set_skill("dongming-xinfa",150);
   set_skill("bihai-force",150);
   set_skill("shuiyun-xiufa",150);
   set_skill("nishang-piaoming",150);
   set_skill("strike",150);
   set_skill("literate",150);
   
   set("max_gin",2000);
   set("max_sen",2000);
   set("max_kee",2000);
   set("force",2000);
   set("max_force",2000);
   create_family("东溟派",5,"护法");
 
   setup();
   carry_object(__DIR__"obj/caiyi")->wear();
   carry_object(__DIR__"obj/whip")->wield();
  
}

void attempt_apprentice(object ob)
{   
	int lev;
	
	if(ob->query("family"))
	if(ob->query("family/family_name")=="东溟派")
	if((int)ob->query("family/generation",1)<=5)
	{   
	   command("say 此话从何说起？\n");
	   return;
	}
	
	if(ob->query("gender")=="男性"){
	
	command("say 我不收男弟子的！你如果诚心投入本派，去找尚仁吧！\n");
	return;
        }
        
        if(ob->query_skill("bihai-force",1)<100){
          command("say 碧海神功是我们东溟派的根基，你不好好学我怎么能收你为弟子呢？");
          return;
        }
        if(ob->query("office_number")<30){
        command("say 你的功绩这么低，我可不要这么懒惰的弟子！\n");
        return;
        }        
	
	if(!ob->query("menpai/dongming2")){
		lev=ob->query_skill("strike",1);
    lev=lev*lev/(lev+100);
    ob->party_reward_skill("whip",lev);
    tell_object(ob,HIY"你从基本掌法中领略到了基本鞭法！\n"NOR);
		
	  ob->set("menpai/dongming2",1);
	  
	}
	command("say 近来战乱纷起，我们东溟未必能置身事外，你可以要好好练习武艺，保护我们门派！\n");
	command("recruit "+ob->query("id"));
	return;
}

int recruit_apprentice(object ob)
{
   if( ::recruit_apprentice(ob) )
     ob->set("class", "dongming2");
}