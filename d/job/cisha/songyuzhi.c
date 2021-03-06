
inherit NPC;

#include <ansi.h>
#include <job_money.h>

string do_job1();
string do_job2();
string do_ok();
void create()
{
   set_name("宋玉致",({ "song yuzhi","song","yuzhi" }) );
        set("gender", "女性" );
       set("age", 22);
   set("long", "她就是宋家堡的宋玉致。据说她是寇仲真心喜欢的人。\n");
       
   set("combat_exp", 300000);
   set("str", 28);
   set("per", 27);
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
   set_skill("anxiang-fuying",100);
   set_skill("force",110);
   set_skill("tiangang-sanjue",100);
   set_skill("poyu-quan",100);
   create_family("宋家堡",5,"门人");
 set("chat_chance",60);
set("chat_msg",({ (:random_move:),}));
   set("shili",([
      "name":"songjia_b",
      ]));
   
   set("inquiry",([
        "任少名":(:do_job1:),
        "刺杀":(:do_job2:),
        "奖励":(:do_ok:),
        ]));
   setup();
   carry_object(__DIR__"chouyi")->wear();
   carry_object(__DIR__"duandao")->wield();
  
}

string do_job1()
{
  object ob;
  object *t;
  int i;
  ob=this_player();
  if(ob->query("combat_exp")<500000)
  return "你的经验太低了，做这个任务太危险了！\n";
   t=ob->query_team();
  if(sizeof(t)>0)
  for(i=0;i<sizeof(t);i++)
       if(objectp(t[i])){
       	
       	 if(t[i]->query("combat_exp")<500000)
       	 return ""+t[i]->name()+"的经验太低了，这太危险了！\n";
	 if(ob->query("combat_exp")>=t[i]->query("combat_exp")){
			  if(ob->query("combat_exp")-t[i]->query("combat_exp")>300000)
				  return "你们的经验相差太大，这很危险！\n";}
		  else{ if(t[i]->query("combat_exp")-ob->query("combat_exp")>300000)
			      return "你们的经验相差太大，这很危险！\n";}}
  if(ob->query_temp("dtsl_job_cisha"))
  return "你还是赶快去九江了，否则走漏了风声就无法刺杀了！\n";
  if(time()-ob->query("busy_time")<100+random(20))
  return "这个任务非常危险，你还是歇歇吧！\n";
  if(ob->query_temp("dtsl_job"))
  return "你正在做其他的任务，先忙其他的吧！\n";
  t=ob->query_team();
  if(sizeof(t)>0)
    for(i=0;i<sizeof(t);i++)
      if(t[i]){
       if(environment(t[i])!=environment(ob)){
       return "你还是把队员召集整齐到这里再问这个问题吧！\n";
       break;}
       t[i]->set_temp("dtsl_job_cisha/step1",1);
       t[i]->set_temp("dtsl_job","刺杀任少名");}
  ob->set_temp("dtsl_job_cisha/step1",1);
  ob->set_temp("dtsl_job","刺杀任少名");
  return "你知道我们曾叁次派死士刺杀任少名，都落得全军覆减\n"+
  "的厄运，或者会重新再考虑这种近乎自杀的计划。\n";
}

string do_job2()
{
   object ob;
   object *t;
   int i;
   ob=this_player();
   if(!ob->query_temp("dtsl_job_cisha/step1"))
    return "你想帮助我们刺杀谁呢？\n";
   t=ob->query_team();
   if(sizeof(t)>0)
    for(i=0;i<sizeof(t);i++)
     if(t[i]){ 
     if(environment(t[i])!=environment(ob)){
       return "你还是把队员召集整齐到这里再考虑刺杀的计划吧！\n";
       break;}
     t[i]->set_temp("dtsl_job_cisha/step2",1);}
   ob->set_temp("dtsl_job_cisha/step2",1);
   if(sizeof(t)<0)
   return "既然你执意如此，那么就计划好就去九江吧。\n";
   else
   return "既然你们执意如此，那么就计划好就去九江吧。\n";
}

string do_ok()
{
  object ob;
  object *t;
  int i;
  int exp,pot,sil;
  ob=this_player();
  if(!ob->query_temp("dtsl_job_cisha"))
  return "你又没帮我做什么事，凭什么来要奖励啊？\n";
  if(!ob->query_temp("dtsl_job_cisha/step4"))
  return "你没能击杀任少名，我怎么给你奖励？\n";
/*  ob->delete_temp("dtsl_job_cisha");
  ob->delete_temp("dtsl_job");
  ob->set("busy_time",time());
  */
  t=ob->query_team();
  if(sizeof(t)>0)
   for(i=0;i<sizeof(t);i++)
   if(t[i]&&environment(t[i])!=environment(ob))
    return "把你的队员先招集齐再说吧！\n";
  if(sizeof(t)>0){
   for(i=0;i<sizeof(t);i++)
   if(t[i]&&environment(t[i])==environment(ob)&&
    t[i]->query_temp("dtsl_job_cisha/step4")&&
    t[i]->query_temp("dtsl_job_cisha/step3")&&
    t[i]->query_temp("dtsl_job_cisha/step2")&&
    t[i]->query_temp("dtsl_job_cisha/step1")){
      exp=230+random(20)-sizeof(t)*10;
      pot=130+random(10)-sizeof(t)*5;
      sil=200+random(100);
      t[i]->add("combat_exp",exp);
      t[i]->add("potential",pot);
      t[i]->add("deposit",sil);
      tell_object(t[i],query("name")+"朝你笑道：谢谢你们了！\n");
      tell_object(t[i],"在这次行动中，你得到了"+HIW+chinese_number(exp)+NOR+"点经验\n"+
                       "                      "+HIY+chinese_number(pot)+NOR+"点潜能\n"+
                       "                      "+MONEY_D->money_str(sil)+"\n");
      tell_object(t[i],"你的钱庄存款增加了！\n");
      t[i]->delete_temp("dtsl_job_cisha");
      t[i]->delete_temp("dtsl_job");
      t[i]->set("busy_time",time());
      add_shili(t[i],exp/3,sil/3);}
      return "谢谢你们为我们做了这么大的事！\n";}
  exp=220+random(20);
      pot=130+random(10);
      sil=200+random(100);
      ob->add("combat_exp",exp);
      ob->add("potential",pot);
      if(ob->query("potential")>ob->query("max_pot"))
	ob->set("potential",ob->query("max_pot"));
      ob->add("deposit",sil);
      tell_object(ob,query("name")+"朝你笑道：谢谢你了！\n");
      tell_object(ob,"在这次行动中，你得到了"+HIW+chinese_number(exp)+NOR+"点经验\n"+
                       "                      "+HIY+chinese_number(pot)+NOR+"点潜能\n"+
                       "                      "+MONEY_D->money_str(sil)+"\n");
      tell_object(ob,"你的钱庄存款增加了！\n");
      ob->delete_temp("dtsl_job_cisha");
      ob->delete_temp("dtsl_job");
      ob->set("busy_time",time());
      add_shili(ob,exp/3,sil/3);
      return "谢谢你为我们做了这么大的事！\n";
}
