
inherit F_MASTER;
inherit NPC;

#include <ansi.h>


int do_action1();

void create()
{
   set_name("突利",({ "tu li","tu","li" }) );
   set("gender", "男性" );		
   set("age",48);
   set("nickname","龙卷风");
   set("long", "他就是“龙卷风”突利，乃颉利之侄，武功高强。\n");       
   set("combat_exp",2500000);
   set_skill("dodge",300);
   set_skill("parry",300);
   set_skill("force",300);
   set_skill("spear",350);
   set_skill("literate",200);
  
   set_skill("yanyang-dafa",300);
   set_skill("canglang-jue",200);
   set_skill("youlong-shenfa",300);  
   set_skill("fuying-spear",350);
   set("max_gin",6000);
   set("max_kee",6000);
   set("max_sen",6000);
   set("force",8000);
   set("max_force",8000);
   create_family("突厥",3,"可汗");
    set("perform_quest/fengsha",1);
    set("perform_quest/fengyu",1);
   set("chat_chance_combat",80);
   set("chat_msg_combat",({
                (: command("perform fengyu") :),
                (: command("perform fengsha") :),
                (: command("execute xiao") :),
        }));
    set("apply_points",200);
   set("inquiry",([
     "护送":(:do_action1:),
    ]));
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
   carry_object(__DIR__"obj/fuying-spear")->wield();
  
}
void attempt_apprentice(object ob)
{   
	
	if(ob->query("family"))
	if(ob->query("family/family_name")=="突厥")
	if((int)ob->query("family/generation",1)<=3)
	{   
	  command("say 此话从何说起？");
	  return;
	}
	if(ob->query("tujue_jun")!="黑狼军"){
            command("say 你没加入我们黑狼军，我可不要你这样的徒弟！");
            return;
        }
        if(ob->query_skill("yanyang-dafa",1)<150){
            command("say 你的炎阳大法修为太低了，叫我如何收你为徒？");
            return;
        }
        if(ob->query("office_number")<40){
        command("say 你的功绩这么低，我可不要这么懒惰的弟子！\n");
        return;
        }
        if(!ob->query_temp("husong_badai_ok")){
          command("say 你先证明你的实力给我看看！");
          return;
        }
                
	command("say 你可要努力学习武功，将来为突厥一统中原尽力！\n");
	command("recruit "+ob->query("id"));
	return;
}

int recruit_apprentice(object ob)
{
   if( ::recruit_apprentice(ob) )
     ob->set("class", "tujue3");
}

int do_action1()
{
  object ob,target;
  string msg;
  
  ob=this_player();
  
  if(ob->query("family")
  &&ob->query("family/family_name")!="突厥"
    ){
    command("say 你真是说笑了！");
    return 1;
  }
  if(ob->query("family"))
	if(ob->query("family/family_name")=="突厥")
	if((int)ob->query("family/generation",1)<=4)
	{   
	  command("say 此话从何说起？");
	  return 1;
	}
  if(!ob->query("family")
    ){
    command("say 你还不是我突厥弟子，如何护送芭黛儿？");
    return 1;
  }
  
  if(ob->query("tujue_jun")=="金狼军"){
      command("say 你既然已经加入了金狼军，就休想再为我办事！");
      return 1;
  }
  if(ob->query_temp("husong_badai")){
      command("say 你到底敢不敢护送？");
      return 1;
  }
  if(ob->query_temp("husong_badai_ok")){
      command("say 你护送芭黛儿足以证明你的实力，我可以收你为徒了！");
      return 1;
  }
  
  target=new(__DIR__"badai");
  target->set_status(ob);
  target->move(environment(ob));
  
  msg="$N朝$n道：你帮我把芭黛儿护送到洛阳的新中桥吧，路上小心我的仇敌！\n\n";
 
  ob->add_temp_array("job_temp_killer",target);
  ob->set_temp("husong_badai",1);
  message_vision(msg,this_object(),ob);
  call_out("killer_come",15,ob);
  return 1;
}

void killer_come(object ob)
{
  object killer;
  
  if(!ob) return;
  if(ob->is_ghost()) return;
  
  killer=new(__DIR__"killer");
  killer->set_status(ob);
  
  tell_object(ob,HIB"你突然感到一阵冷风吹来！\n\n"NOR);
  
  killer->move(environment(ob));
  
  killer->kill_ob(ob);
  
  return;
}
