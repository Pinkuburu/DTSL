
inherit F_MASTER;
inherit NPC;

#include <ansi.h>

int do_action1();

void create()
{
   set_name("拓跋玉",({ "tuoba yu","tuoba","yu" }) );
   set("gender", "男性" );		
   set("age",24);
   set("long", "他就是毕玄的徒弟。\n");       
   set("combat_exp",600000);
   set_skill("dodge",150);
   set_skill("parry",150);
   set_skill("force",150);
   set_skill("whip",150);
   set_skill("literate",150);
  
   set_skill("yanyang-dafa",150);
   set_skill("canglang-jue",150);
   set_skill("youlong-shenfa",150);  
   set_skill("feiwo-whip",150);
  
   set("max_gin",2000);
   set("max_kee",2000);
   set("max_sen",2000);
   set("force",2000);
   set("max_force",2000);
   create_family("突厥",5,"武士");
   set("inquiry",([
     "入伍":(:do_action1:),
    ]));
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
   carry_object(__DIR__"obj/whip")->wield();
  
}
void attempt_apprentice(object ob)
{   
	int lev;
	
	if(ob->query("family"))
	if(ob->query("family/family_name")=="突厥")
	if((int)ob->query("family/generation",1)<=5)
	{   
	  command("say 此话从何说起？");
	  return;
	}
	if(ob->query("tujue_jun")!="金狼军"){
            command("say 你没加入我们金狼军，我可不要你这样的徒弟！");
            return;
        }
        if(ob->query_skill("yanyang-dafa",1)<100){
            command("say 你的炎阳大法修为太低了，叫我如何收你为徒？");
            return;
        }
        if(ob->query("office_number")<30){
        command("say 你的功绩这么低，我可不要这么懒惰的弟子！\n");
        return;
        }
        lev=ob->query_skill("finger",1);
        lev=lev*lev/(lev+100);
        ob->party_reward_skill("whip",lev);
        tell_object(ob,HIY"你从基本指法中领略到了基本鞭法！\n"NOR);
        if(!ob->query("menpai/tujue2")){
         
          ob->set("menpai/tujue2",1);

	}
	command("say 你可要努力学习武功，将来为突厥一统中原尽力！\n");
	command("recruit "+ob->query("id"));
	return;
}

int recruit_apprentice(object ob)
{
   if( ::recruit_apprentice(ob) )
     ob->set("class", "tujue2");
}

int do_action1()
{
  object ob;
  string msg;
  
  ob=this_player();
  
  if(ob->query("family")
  &&ob->query("family/family_name")!="突厥"
    ){
    command("say 你真是说笑了！");
    return 1;
  }
  if(!ob->query("family")
    ){
    command("say 你还不是我突厥弟子，如何入伍？");
    return 1;
  }
  
  if(ob->query("tujue_jun")=="黑狼军"){
      command("say 你既然已经加入了黑狼军，就休想再进入我金狼军！");
      return 1;
  }
  if(ob->query("tujue_jun")=="金狼军"){
      command("say 你已经入伍了。");
      return 1;
  }
 
  msg="$N朝$n道：我突厥分为黑狼军和金狼军，从今后你就是我金狼军的战士了！\n\n";
 
  ob->set("tujue_jun","金狼军");
  message_vision(msg,this_object(),ob);
  
  return 1;
}
