
inherit F_MASTER;
inherit NPC;
void create()
{
   set_name("法难",({ "fa nan","fa","nan" }) );
        set("gender", "男性" );
		
        set("age", 34);
   set("long", "他就是人称“恶僧”的法难。\n");
       
   set("combat_exp",300000);
   set("per",4);
  
   set_skill("dodge",100);
   set_skill("parry",100);
   set_skill("force",100);
   set_skill("strike",100);
   set_skill("cuff",100);
   
   set_skill("jiutian-huanzhang",100);
   set_skill("literate",100);
   set_skill("tianmo-dafa",100);
   set_skill("tianmo-huanzong",100);
  
   set("max_gin",1000);
   set("max_kee",1000);
   set("max_sen",1000);
   set("force",1000);
   set("max_force",1000);
   create_family("阴癸派",7,"弟子");
   set("class","yin1");
   setup();
   
}
void attempt_apprentice(object ob)
{   
	if(ob->query("family"))
	if(ob->query("family/family_name")=="阴癸派")
	if((int)ob->query("family/generation",1)<=7)
	{   
	   command("say 此话从何说起？\n");
	   return;
	}
	
	if(ob->query("gender")=="女性"){
	
	command("say 我不收女弟子的！你如果诚心投入本派，去找“艳尼”常真吧！\n");
	return;
	}
	
	command("say 好！希望你将来能一统魔道，长我阴癸派名声！\n");
	command("recruit "+ob->query("id"));
	return;
}

int recruit_apprentice(object ob)
{
   if( ::recruit_apprentice(ob) )
     ob->set("class", "yin1");
}

