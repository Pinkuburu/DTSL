inherit NPC;
#include <ansi.h>
#include <org.h>

int do_action1();

void create()
{
   set_name("商秀珣",({ "shang xiuxun","shang"}) );
   set("gender", "女性" );
		
   set("age", 25);
   set("long", "她就是飞马场主。仪态万千，乌黑漂亮的\n"+
               "秀发像两道小瀑布般倾泻在她刀削似的香\n"+
               "肩处，美得异乎寻常，她那对美眸深邃难\n"+
               "测，浓密的眼睫毛更为她这双像荡漾着最\n"+
               "香最醇的仙酿的凤目增添了她的神秘感。\n");
       
   set("combat_exp",600000);
   set("str", 24);
   set("per", 27);
   set_skill("unarmed",170);
   set_skill("dodge",170);
   set_skill("parry",170);
   set_skill("sword",170);
   set_skill("qingxuan-jianfa",170);

   set_skill("babu-ganchan",170);
  
   set("shili",([
       "name":"feima_b",
       "leader":"feima_b",
       ]));
   set("shili_id","feima");
   
   set("inquiry",([
       "两派六道":(:do_action1:),
      ]));
   setup();
   carry_object(__DIR__"obj/shayi")->wear();
   carry_object(__DIR__"obj/changjian")->wield();
  
}


int accept_gage(object me)
{
   this_object()->fight_ob(me);
   me->fight_ob(this_object());
   return 1;
}

int accept_object(object me,object obj)
{
    
    if(!obj->id("baihuajian_quest_obj"))
     return notify_fail("我可不随便要别人的东西！\n");
    
    me->set_temp("bai_huajian/step1",1);
    command("say 谢谢你给我带来这么好吃的东西！");
    return 1;
}

int do_action1()
{
   object ob;
   
   ob=this_player();
   
   command("say 两派就是阴癸派和花间派，两派一向以阴癸派为首，\n"+
           "那并非因花间不如阴癸，只是花间派每代只传一人。所以\n"+
           "身份特别隐秘，连魔门的人，亦不知道谁是花间派的传人。\n");
   if(ob->query_temp("bai_huajian/step1")){
       ob->delete_temp("bai_huajian/step1");
       ob->set_temp("bai_huajian/step2",1);
   }
   return 1;
}

int accept_enroll(object me)
{
	object ob;
	ob=this_object();
	if(me->query("shili"))
	if(me->query("shili/name")!=ob->query("shili/name"))
	 return notify_fail("我们飞马牧场可不要其他帮派的人！\n");
	if(!ORG_D->is_leader("feima"))
	 return notify_fail("我已经不是场主了，和我说没用的！\n");
	if(me->query("shili/name")==ob->query("shili/name"))
	 return notify_fail("你高声喊道：誓死效忠飞马牧场！\n");
	me->set_temp("mark_join",ob->query("shili/name"));
	message_vision("$N朝$n笑道：希望$n能好好干，使我们飞马牧场更加强大！\n",ob,me);
	tell_object(me,HIW"\n请去势力名单榜处打 "HIG"join"HIW" 命令就算加入了！\n\n"NOR);
	
	return 1;
}