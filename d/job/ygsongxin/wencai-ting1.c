

inherit NPC;



#include <job_money.h>

#include <ansi.h>



#define MBUG(x) (tell_object(find_player("inwind"),sprintf("%s: %O\n",__FILE__,(x))))

string give_job();

string do_abandon();

string do_quest1();

int do_quest2();

string do_mghs_quest1();

int do_answer(string arg);



string *dir1=({

"/d/huashan","/d/emeishan"

});

string *dir2=({

"/d/suiye","/d/dingxiang","/d/wuyishan"

});

string *dir3=({

"/d/hengshan","/d/taishan","/d/dabashan"

});



void create()

{

   set_name("闻采婷",({ "wen caiting","wen" }) );

   set("gender", "女性" );

		

   set("age", 32);

   set("long", "她是阴癸派的闻采婷，她的魔功在江湖上也是非常闻名。\n");

       

   set("combat_exp",500000);

   set("str", 25);

   set("per", 25);

   set("attitude", "peaceful");

   set_skill("unarmed",170);

   set_skill("dodge",170);

   set_skill("parry",170);

   set_skill("force",170);

   set_skill("sword",170);

   set_skill("strike",170);

   set_skill("cuff",170);

   set_skill("literate",170);

   set_skill("jiutian-huanzhang",170);

   set_skill("tianmo-dafa",170);

   set_skill("tianmo-jianfa",170);

   set_skill("tianmo-huanzong",170);

   set_skill("tianmo-dai",170);  

   set_skill("meigong-huanshu",200);

   set("gin",3000);

   set("max_gin",3000);

   set("kee",3000);

   set("max_kee",3000);

   set("sen",3000);

   set("max_sen",3000);

   set("force",3000);

   set("max_force",3000);

   create_family("阴癸派",5,"长老");

   set("target_id","####");

   

   set("inquiry",([	

	   "送信":(:give_job:),

            "放弃":(:do_abandon:),

	   "天魔阵":(:do_quest1:),

	   "效劳":(:do_quest2:),

	   "面首":(:do_mghs_quest1:),

	   ]));  

   setup();

  

}



void init()

{

   add_action("do_answer","answer");

}



string give_job()

{

	object me,letter;

	object owner;

	string *dirs,str;

	

	me=this_player();

	if(me->query_temp("zhu_sx")) return "你还是先送完手中的信吧!\n";

	

	

        if(time()-me->query("busy_time")<=10)

		return "你还是先歇歇吧！\n";

	if(me->query_temp("dtsl_job"))

	return "你正在做其他任务，还是先忙其他的吧！\n";

	

	if(me->query("combat_exp")<200000)

	 dirs=dir1;

	else

	 if(me->query("combat_exp")<500000)

	 dirs=dir1+dir2;

	else

	 dirs=dir1+dir2+dir3;

	

	owner=new(__DIR__"owner");

	

	if(!owner->set_status(me))

	return "接信的使者出问题了，快去报告巫师！\n";

	

	if(!random_place(owner,dirs))

	return "接信的使者在哪里呢？让我想想... ...\n";

	

	if(!environment(owner))

	return "接信的使者在哪里呢？让我想想... ...\n";

	

	letter=new(__DIR__"letter");

	letter->set("target",owner);

	letter->set("long","这是一封送给"+HIC+owner->name()+NOR+"的信。\n");

	letter->set("owner",me);

	letter->move(me);

	me->set_temp("zhu_sx",1);

	me->set_temp("dtsl_job","阴癸送信任务");

	me->set_temp("songxin/name",owner->query("name"));




	if((int)me->query("combat_exp",1)>=800000)

	   {   
	   		 me->set_temp("need_killer",1);
	   	call_out("killer_come",30+random(10),me);

            str="路上可要小心！\n";

	}

	else str="";

	tell_object(me,query("name")+"给了一封"+letter->query("name")+"。\n");

	return "好吧，麻烦你帮我把这封"+letter->query("name")+CYN+"送给"+MISC_D->find_place(environment(owner))+

	 "的"+owner->name()+"，千万不要走漏了消息！\n"+

	       str;

	

	 

}







string do_abandon()

{

   object ob;

   object letter;

   object owner;

   

   ob=this_player();

   

   if(!ob->query_temp("zhu_sx"))

   return "你在说什么？我可以一点也不懂啊！\n";

   

   

   if(objectp(letter=present("letter",ob)))

{

   if(objectp(owner=letter->query("target")))

{

MBUG(owner);

    destruct(owner);

}

    destruct(letter);

}

   ob->delete_temp("zhu_sx");

   ob->delete_temp("dtsl_job");

  ob->delete_temp("songxin/ob");

  ob->delete_temp("songxin/ob");

   ob->delete_temp("need_killer");

   ob->delete_temp("need_killer_flags");

   return "象你这种没有胆量的人真是给我丢脸！\n";

}

void killer_come(object me)
{
  object killer;
   object killer2;
   object letter;
   
   if(!me)
    return;
   if(me->is_ghost())
    return;
   
   if(!me->query_temp("zhu_sx"))
    return;
    
   tell_object(me,HIB"\n似乎有人从你的背后袭来！\n\n"NOR);
   killer=new("/d/job/ygsongxin/killer");
        
        killer->set_status(me);                         
        killer->move(environment(me));
        message_vision("\n$N凛然道:邪教之人拿命来!\n\n",killer);
        me->add_temp_array("job_temp_killer",killer);
        killer->kill_ob(me);
  

  return;
}       


string do_quest1()

{

   object ob;

  

  ob=this_player();

  

  if(ob->query("dtsl_quest_yinguifinal"))

  return "凭你的功夫学习天魔阵太可惜了！\n";

  

  if(ob->query_temp("tmz_quest/pass_wen"))

  return "你的功夫我已经考验过了，你去问其他长老吧！\n";

  

  ob->set_temp("tmz_quest/wen_step1",1);

  

  return "想学天魔阵？先打败我再说吧！\n";

}



int surrender(object killer,object victim)

{

   if(!killer->query_temp("tmz_quest/wen_step1"))

   return 1;

   killer->delete_temp("tmz_quest/wen_step1");

   killer->set_temp("tmz_quest/wen_step2",1);

   

   message_vision(CYN"\n$N"+CYN+"脸色一变，朝$n"+CYN+"道："+RANK_D->query_respect(killer)+"果然身手不凡！\n"+

   "不过你还要给我办点事情才可以！\n"NOR,victim,killer);

   return 1;

}





int do_action1(object ob)

{

   string msg;

   

   msg="\n$N朝$n抛了个媚眼：本座近来久无新欢，你来陪本座一会吧！\n";

   message_vision(msg,this_object(),ob);

   call_out("do_msg2",1,ob);

   return 1;

}



int do_action2(object ob)

{

    string msg;

    

    msg="\n$N朝$n娇笑道：好，本座就教你如何迷惑男子！\n";

    message_vision(msg,this_object(),ob);

    call_out("show_msg2",1,ob);

    return 1;

}

void do_msg2(object ob)

{

  string msg;

  

  if(!ob) return;

  

  msg="\n$N一伸玉臂，将$n揽了过去。\n"+

      "$n只觉得香气扑鼻，有些意乱神迷了！\n";

  message_vision(msg,this_object(),ob);

  call_out("do_msg3",1,ob);

}



void do_msg3(object ob)

{

  string msg;

  

  if(!ob) return;

  

  if(ob->query("sen")<300){

   msg="\n$N一把推开$n，怒道：看你一点精神也没有，还是离本座远点吧！\n";

   message_vision(msg,this_object(),ob);

  }

  msg="\n$N和$n紧紧抱在了一起，$n完全迷失了神智。\n"+

      "两人似乎已经将周围的事物忘得一干二净。\n"+

      "＃＠＃％＆＆＊＆％￥＃\n\n";

  message_vision(msg,this_object(),ob);

  call_out("do_msg4",1,ob);

}



void do_msg4(object ob)

{

  string msg;

  

  if(!ob) return;

  

  msg="\n$n有些神智失落地站了起来。\n"+

      "$N露出满意的笑容，摸了摸$n的脸颊。\n"+

      "$N道：我这里的考验已经通过了！你再去问问其他长老的意见吧！\n";

  message_vision(msg,this_object(),ob);

  ob->set_temp("tmz_quest/pass_wen",1);

  return;

}



void show_msg2(object ob)

{

   string msg;

  

   if(!ob) return;

   

   msg="\n$N轻移到$n身边，轻声对$n说着「媚功幻术」的诀窍。\n"+

       "$n听着，脸不由得红了。\n";

   message_vision(msg,this_object(),ob);

   call_out("show_msg3",1,ob);

}



void show_msg3(object ob)

{

   string msg;

  

   if(!ob) return;

   

   msg="\n$N娇笑着对$n说着什么，手心按到了$n的背上。\n"+

       "$n低头想了一会，似乎对「媚功幻术」有了一些领悟。\n";

   message_vision(msg,this_object(),ob);

   call_out("show_msg4",1,ob);

}



void show_msg4(object ob)

{

   string msg;

  

   if(!ob) return;

   

   msg="\n$N朝$n一笑：好好学习「媚功幻术」，以后天下的男子就都是\n"+

       "你的囊中之物了！\n"+

       "$N道：我这里的考验已经通过了！你再去问问其他长老的意见吧！\n";   

   message_vision(msg,this_object(),ob);

   ob->improve_skill("meigong-huanshu",1000);

   ob->set_temp("tmz_quest/pass_wen",1);

}



int do_quest2()

{

  object ob;

  

  ob=this_player();

  

  if(!ob->query_temp("tmz_quest/wen_step2")){

    command("xixi");

    command("say 你想为我效劳什么啊？");

    return 1;

  }

  

  ob->delete_temp("tmz_quest/wen_step2");

  if(ob->query("gender")=="男性")

   return do_action1(ob);

  else

   return do_action2(ob);

}



string do_mghs_quest1()

{

   object ob;

   

   ob=this_player();

   

   if(ob->query("dtsl_quest_meigong-huanshu"))

   return "你自己用媚功幻术去迷惑吧，总是问我做什么？\n";

   

   if(ob->query("gender")=="男性")

   return "你想当面首吗？想吗？想当你就说啊？不说我怎么知道你想啊？... ...\n";

   if(ob->query_per()<29)

   return "看你长得这个样子！哪个男人会被你迷惑？！\n";

   

   if(ob->query("couple"))

   return "结婚的女子还问这个问题？？你比我还厉害啊！\n";

   

   if(ob->query("age")>60)

   return "你的年龄也太大点了吧？真是老了你的人，老不了你的心啊！\n";

   

   if(ob->query("class")=="bonze"){

     command("kao1");

     return "连尼姑也想干这个，什么世道啊？... ...\n";

   }

   

   ob->set_temp("do_mghs_quest1",1);

   return RANK_D->query_respect(ob)+"春心动了，要养面首啊？我有一套媚功你学不学啊？\n";

}



int is_apprentice_of(object ob)

{

   return 1;

}



int recognize_apprentice(object ob)

{

   return 1;

}



int prevent_learn(object me, string skill)

{

    if(skill!="meigong-huanshu")

    return 1;

    if(!me->query("dtsl_quest_meigong-huanshu"))

    return 1;

    if(me->query_skill("meigong-huanshu",1)>me->query_per()*6)

    return 1;

    

    return 0;

}



int do_answer(string arg)

{

   object ob;

   

   ob=this_player();

   

   if(!ob->query_temp("do_mghs_quest1")){

     return 0;

   }

   if(arg!="学"){

     command("say 你到底想说什么啊？");

     return 1;

   }

   

   ob->set("dtsl_quest_meigong-huanshu",1);

   command("say 好，以后你就和我学习「媚功幻术」，以后天下的男子都在你的掌握之中！");

   return 1;

}

