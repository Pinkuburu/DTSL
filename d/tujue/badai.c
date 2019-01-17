
inherit NPC;

void create()
{
   set_name("芭黛儿",({ "ba dai","ba" }) );
   set("gender", "女性" );
		
   set("age",22);
   set("long", "她是突利可汗钦定的小妻子。\n");
       
   set("combat_exp",300000);
   set("per", 25);
   set("attitude", "peaceful");
   set_skill("dodge",130);
   set_skill("parry",130);
   set_skill("force",130);

   setup();
  
}

void init()
{
   add_action("do_ok","task");
}

int set_status(object ob)
{
  set_leader(ob);
  set("target_id","###");
  set("job_owner",ob);
  return 1;
}

int do_ok(string arg)
{
  object ob;
  
  ob=this_player();
  
  if(query("job_owner")!=ob)
   return 0;
  if(!arg||arg!="ok")
  return notify_fail("使用 task ok 来结束任务。\n");
  if(base_name(environment(ob))!="/d/luoyang/xinzhongqiao2"){
    command("say 你护送的地方不对啊！");
    return 1;
  }
  if(!ob->query_temp("husong_badai_killer")){
    command("say 本来护送我是为了考验你，可是你没杀死杀手，哎，那算了！");
    destruct(this_object());
    return 1;
  }
  ob->delete_temp("husong_badai_killer");
  ob->delete_temp("husong_badai");
  ob->set_temp("husong_badai_ok",1);
  command("say 谢谢你了！");
  destruct(this_object());
  return 1;
}
  