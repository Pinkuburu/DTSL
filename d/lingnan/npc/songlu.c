
inherit NPC;
//inherit F_MASTER;
#include <ansi.h>
void create()
{
   set_name("宋鲁",({ "song lu","song","lu" }) );
        set("gender", "男性" );
		set("nickname","银龙");
       set("age", 42);
   set("long", "他就是宋家堡的宋鲁。\n");
       
   set("combat_exp", 300000);
   set("str", 28);
   set("per", 24);
   set("attitude", "peaceful");
   set("gin",1000);
   set("max_gin",1000);
   set("kee",1000);
   set("max_kee",1000);
   set("sen",1000);
   set("max_sen",1000);
   set("force",1000);
   set("max_force",1000);
   set_skill("tiandao-bajue",100);
   set_skill("blade",100);
   set_skill("dodge",100);
   set_skill("parry",100);
   set_skill("unarmed",100);
   set_skill("cuff",100);
   set_skill("literate",100);
   set_skill("anxiang-fuying",100);
   set_skill("force",110);
   set_skill("tiangang-sanjue",100);
   set_skill("poyu-quan",100);
 
   set_skill("staff",200);
   
   create_family("宋家堡",5,"门人");
   set("shili",([
      "name":"songjia_b",
      ]));
   setup();
   carry_object(__DIR__"obj/chouyi")->wear();
   carry_object(__DIR__"obj/guai")->wield();
  
}

/*
void attempt_apprentice(object ob)
{   
	if(ob->query("family"))
		if((string)ob->query("family/family_name")!="宋家堡")
		{
		 tell_object(ob,"宋鲁皱皱眉头：我们宋家堡从来不收其他门派叛徒的！\n");
	  return;
		}
		else if(ob->query("family/generation")<this_object()->query("family/generation"))
		{ tell_object(ob,"宋鲁笑笑：师叔真是会开玩笑！\n");
		return;}
	if(ob->query("vocation")=="杀手")
	{ tell_object(ob,"宋鲁皱皱眉头：我们宋家堡从来不收杀手的！\n");
	  return;
	}
	if(ob->query("beipan")>=3)
	{  tell_object(ob,"宋鲁厌烦道：象你这种多个势力的叛徒，我可不要！\n");
	   return;
	}
	  
	command("say 好,只要在宋家堡好好干,保证你将来啸傲江湖!\n");
	command("recruit "+ob->query("id"));
	return;
}

int recruit_apprentice(object ob)
{
   if( ::recruit_apprentice(ob) )
     ob->set("class", "song1");
}

*/