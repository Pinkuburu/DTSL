#include <ansi.h>
#include <job_money.h>
inherit NPC;
string give_job();
string abandon_job();
int do_ok(string arg);
void create()
{
   set_name("李财主",({ "li caizhu","li","caizhu" }) );
        set("gender", "男性" );
        set("age", 52);
   set("long", "这是杭州的大富李财主，近来他正在为女儿举办比武招亲。\n");
       
   set("combat_exp", 50000);
   set("str", 10);
   set("per", 22);
   set("attitude", "friendly");
/*   set("inquiry",([
	   "比武招亲":(:give_job:),
	   "放弃":(:abandon_job:),
	   ]));*/
   set("chat_chance",30);
   set("chat_msg",({
	   (:random_move:),
   }));
   setup();
 //  carry_object(__DIR__"obj/chouyi")->wear();
  
}

void init()
{
	add_action("do_ok","task");
}

string give_job()
{
	object me,ob,letter;
	object *usr;
	int i,j;
	me=this_player();ob=this_object();
	if(me->query("combat_exp")<100000)
	return "你的本领这么低，怎么帮我啊？\n";
	
	if(me->query_temp("li_job"))
		return "你还是先做完手头的事吧！\n";
	if(me->query_temp("li_song_job"))
      	return "你还是先做完手头的事吧！\n";
	if(time()-me->query("busy_time")<=30+random(10))
		return "你还是先歇歇吧！\n";
	if(me->query_temp("dtsl_job"))
   return "你正在做其他任务，先忙其他的吧！\n";
      //  if(!valid_do_job(me,"licaizhu"))
      //  return "你的武功这么高，我可没那么多的钱雇佣你。\n";
      if(me->query("combat_exp")<500000){
      	
      	usr=users();
      	for(j=0;j<sizeof(usr);j++){
      	 i=random(sizeof(usr));
      	 if(!interactive(usr[i])) continue;
      	 if(!living(usr[i])) continue;
      	 if(wizardp(usr[i])) continue;
      	 if(query_ip_name(usr[i])==
      	    query_ip_name(me)) continue;
      	 if(usr[i]==me) continue;
      	 break;}
      	 if(j==sizeof(usr))
      	 return "给谁送请柬呢？让我想想看。\n";
       me->set_temp("li_song_job",1);
      	me->set_temp("dtsl_job","杭州李财主任务");
      	letter=new(__DIR__"letter");
       letter->set("target_id",usr[i]->query("id"));
       letter->move(me);
       return "好吧，你拿着这封请柬，送(song)给"+usr[i]->name()+"吧！\n";}
   me->set_temp("dtsl_job","杭州李财主任务");
	me->set_temp("li_job",1);
       
   return "我家后院有个比武招亲的擂台，杨广这个奸贼已经派\n"+
          "自己的手下来参加比武招亲，想抢夺我的女儿，你去\n"+
          "帮我把那几个官兵打败吧！我一定会重重酬谢你的！！\n";
	
}
string abandon_job()
{
  object ob;
  ob=this_player();
  if(!ob->query_temp("li_job"))
  return "你在说什么？我一点也听不懂！\n";
  ob->delete_temp("li_job");
  ob->delete_temp("dtsl_job");
  ob->delete_temp("target_come");
  ob->delete("busy_time");
  return "如今的武林豪侠真是越来越少了，唉... ...\n";
}
  
int do_ok(string arg)
{
	object me,ob,money;
	int exp,i,sil,pot,famous,score;
	me=this_player();i=0;
	if(!me->query_temp("li_job"))
		return notify_fail("什么？\n");
	if(!arg||arg!="ok")
		return notify_fail("如果复命，请用task ok.\n");
	if(!me->query_temp("defence_ok"))
		return notify_fail("你不是亲自杀死的官兵，我不会酬谢你的！\n");
	exp=5+random(5);
	sil=500+me->query("max_pot");
	pot=3+random(2);	
	me->add("combat_exp",exp);
	me->add("potential",pot);
	me->add("deposit",sil);
	add_shili(me,exp/2,20+random(2));
	me->delete_temp("defence_ok");
	me->delete_temp("li_job");
	me->delete_temp("dtsl_job");
	me->delete_temp("target_come");
	me->set("busy_time",time());
  	tell_object(me,"李财主满脸堆笑：谢谢"+RANK_D->query_respect(me)+"了！\n"+
  	               "李财主给了你"+MONEY_D->money_str(sil)+"做为报酬。\n");
  	tell_object(me,"你的钱庄存款增加了！\n");
	return 1;
}
