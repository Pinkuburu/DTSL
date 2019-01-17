#include <ansi.h>
#include <job_money.h>
inherit ITEM;
mapping name=([
HIY"九转灵珠"NOR:"jiuzhuan lingzhu",HIW"夜明珠"NOR:"yeming zhu",HIG"翡翠项链"NOR:"necklace",HIW"白玉白虎"NOR:"tigger",
HIY"金娃娃"NOR:"jin wawa",HIC"避水珠"NOR:"bishui zhu",HIG"翡翠珊瑚"NOR:"shan hu",HIW"白玉美人"NOR:"baiyu meiren",
HIC"夜光手镯"NOR:"shou zhuo",HIY"金砖"NOR:"jin zhuan",HIW"白玉萧"NOR:"xiao",HIG"猫眼"NOR:"mao yan",HIG"玛瑙"NOR:"ma nao",
HIG"琴谱"NOR:"qin pu",HIY"金项圈"NOR:"xiang quan",HIY"钻石"NOR:"zuan shi",HIW"天山雪莲"NOR:"xue lian",HIW"千年人参"NOR:"ren shen",
]);

//#include "want_owner.h"

void create()
{
   string *n;int i;
   string *w;
   
   n=keys(name);
   i=random(sizeof(n));
   set_name(n[i],({name[n[i]]}));
   set_weight(5000);
   
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("no_sell",1);
     set("unit", "个");
     set("value", 0);
     set("baowu",1);
     
   }
   setup();
   
}

/*

string *part=({"left","right","up","down","center"});
string to_part(string arg)
{
   switch(arg){
   case "left":return "左边";
   case "right":return "右边";
   case "up":return "上边";
   case "down":return "下边";
   case "center":return "中间";}
}
string long()
{
  
  string *w;
  int i;
  if(query("long")) return query("long");
  if(random(100)>60){
    w=keys(want_owner);
    i=random(sizeof(w));
    set("want_owner",want_owner[w[i]]);
    set("long","据说这是"+w[i]+"一直想要的宝物。\n");}
  else 
  if(random(100)==38){
  	set_name(YEL"羊皮"NOR,({"yang pi","pi"}));
  	i=random(sizeof(part));
  	set("part",part[i]);
  	set("quest",1);
  	set("long","看起来这是一幅羊皮做的图的"+to_part(part[i])+"部分。\n");}
  else
  set("long","这个一个罕见的宝物。\n");
  return query("long");
}


void init()
{
  if(!query("last_time"))
   set("last_time",time());
  add_action("do_give","xianbao");
  add_action("do_name","want");
  add_action("do_hecheng","hecheng");
}

int clean_up()
{
  if(time()-query("last_time")<300)
   return 0;
  return 1;
}


int do_give(string arg)
{
   object ob;
   object target;
   object q_ob;
   int exp,pot;
   string name,target_name;
  
   ob=this_player();
   if(!query("want_owner")) return 0;
   if(!arg||sscanf(arg,"%s %s",target_name,name)!=2)
   return notify_fail("你要献给谁什么宝物？\n");
   if(!objectp(target=present(target_name,environment(ob))))
   return notify_fail("这里没有这个人！\n");
   if(!present(name,ob))
   return notify_fail("你身上没有这个东西！\n");
   if(present(name,ob)->query("want_owner")!=base_name(target))
   return notify_fail(target->name()+"一摇头：这个东西我可不想要！\n");
   if(present(name,ob)->query("give_weapon")==base_name(target))
   return notify_fail(target->name()+"说道：你到底想要什么名字的兵器？\n");
   message_vision("$N朝$n笑道：谢谢帮我找到这么珍贵的东西！\n",target,ob);
   
   
   if(ob->query("combat_exp")>=3000000){
   	q_ob=new("/d/job/questjob/quest"+(random(TOTAL_Q_JOB)+1));
   	q_ob->move(ob);
   	tell_object(ob,target->name()+"给了你一块符文\n");}
   	
   if(ob->query_temp("dm_job_find")){
   ob->delete_temp("dm_job_find");
   ob->delete_temp("dm_job_find_where");
   ob->delete_temp("have_killer");
   ob->delete_temp("dtsl_job");}
     
   exp=230+random(40);
   pot=110+random(10);
   ob->add("combat_exp",exp);
   ob->add("potential",pot);
   if(ob->query("potential")>ob->query("max_pot"))
     ob->set("potential",ob->query("max_pot"));
   tell_object(ob,target->name()+"奖励了你"+HIW+chinese_number(exp)+NOR+"点经验。\n");
   tell_object(ob,"奖励了你"+HIY+chinese_number(pot)+NOR+"点潜能。\n");
   add_shili(ob,exp/10,1);
   
   destruct(present(name,ob));
   return 1;
}


int do_hecheng(string arg)
{
   object ob;
   object part1,part2,part3,part4,part5;
   string p1,p2,p3,p4,p5;
   string *content;
   int i;
   object baowu;
   
   ob=this_player();
   if(!arg||sscanf(arg,"%s and %s and %s and %s and %s",
    p1,p2,p3,p4,p5)!=5)
   return notify_fail("你要合成什么？\n");
   if(!objectp(part1=present(p1,ob)))
   return notify_fail("你身上没有"+p1+"。\n");
   if(!objectp(part2=present(p2,ob)))
   return notify_fail("你身上没有"+p2+"。\n");
   if(!objectp(part3=present(p3,ob)))
   return notify_fail("你身上没有"+p3+"。\n");
   if(!objectp(part4=present(p4,ob)))
   return notify_fail("你身上没有"+p4+"。\n");
   if(!objectp(part5=present(p5,ob)))
   return notify_fail("你身上没有"+p5+"。\n");
   if(!part1->query("quest")||!part2->query("quest")||
   !part3->query("quest")||!part4->query("quest")||
   !part5->query("quest")||!query("quest"))
   return notify_fail("这些东西不能合成在一起。\n");
   content=({"left","right","up","down","center"});

     if(member_array(part1->query("part"),content)==-1)
      return notify_fail("这些东西不能合成在一起。\n");
      content=content-({part1->query("part")});
     if(member_array(part2->query("part"),content)==-1)
      return notify_fail("这些东西不能合成在一起。\n");
      content=content-({part2->query("part")});
     if(member_array(part3->query("part"),content)==-1)
      return notify_fail("这些东西不能合成在一起。\n");
      content=content-({part3->query("part")});
     if(member_array(part4->query("part"),content)==-1)
      return notify_fail("这些东西不能合成在一起。\n");
      content=content-({part4->query("part")});
     if(member_array(part5->query("part"),content)==-1)
      return notify_fail("这些东西不能合成在一起。\n");
      content=content-({part5->query("part")});
   tell_object(ob,"你将这几个羊皮小心地拼凑了起来。\n");
   baowu=new(__DIR__"map");
   baowu->move(ob);
   if(part1!=this_object())
   destruct(part1);
   if(part2!=this_object())
   destruct(part2);
   if(part3!=this_object())
   destruct(part3);
   if(part4!=this_object())
   destruct(part4);
   if(part5!=this_object())
   destruct(part5);
   destruct(this_object());
   return 1;
}

*/