
inherit ROOM;
inherit F_SAVE;
#include <ansi.h>
#include <job_money.h>
#include <org.h>
int do_qu(string arg);
int do_list();
int do_biwu(string arg);
int do_clear();
string wiz_refer();
string query_save_file()
{
  return "/data/npc/boss/leitai_save_file";
}

void create()	
{
	set("short", HIR"比武台"NOR);
	set("long", @LONG
这里是天下帮会比武的擂台。帮会比武每一个月举行一次，
擂台的正上方挂着一个大牌匾，上面写着：以武会友四个大字，
擂台两边还挂着几个大红灯笼。这个擂台距离地面大约有三仗高，
而且没有梯子，只有功夫相当高的人才可以上去比武。这里有兵
器架「jia」，你可以从上面取「qu」兵器。旁边还有一块供巫师
观看的牌子「pai」。
LONG);
    
 	set("exits",([
 	  "eastdown":__DIR__"kantai3",
 	  "southdown":__DIR__"kantai2",
 	  "westdown":__DIR__"kantai1",
 	  ]));
 	set("no_death",1);
 set("leitai",1);
 	set("no_sleep",1);
 	set("no_channel","还是好好比武吧！\n");
 	set("no_get",1);
 	set("no_quit",1);
 	set("no_fight",1);
 	set("broadcast",1);
 	set("end_fight",1);
 	set("item_desc",([
 	"jia":"这是一个兵器架，上面有刀(blade)"+
 	      "剑(sword)、锤(hammer)、匕首(dagger)、\n"+
 	      "矛(fork)、斧子(axe)、枪(spear).杖(staff)"+
 	      "你可以qu xx来拿兵器。\n",
 	"pai":(:wiz_refer:),
 	      ]));
      setup();
      restore();
	
}

string wiz_refer()
{
  object ob;
  ob=this_player();
  if(!wizardp(ob))
  return "这是让巫师看的牌子，你还是专心比武吧！\n";
  return "请使用 biwu id1 with id2 来开始比武。\n";
}

void init()
{
add_action("do_qu","qu");
add_action("do_list","list");
add_action("do_biwu","biwu");
add_action("do_clear","clear");
}	

int broadcast(string str)
{
  object *usr;
  usr=filter_array(users(),"filter_user",this_object());
  message("system",YEL"【比武擂台】 :"NOR+str,usr);
  return 1;
}

int filter_user(object ob)
{
  if(environment(ob)&&environment(ob)->query("can_receive_fight_msg"))
  return 1;
  else return 0;
}
int do_qu(string arg)
{
  object ob,weapon;
  ob=this_player();
  if(ob->is_busy())
  return notify_fail("你正忙着呢！\n");
  if(!arg)
  return notify_fail("你要拿什么？\n");
  if(ob->is_fighting())
  ob->receive_damage("sen",-20);
  weapon=new(__DIR__+arg);
  if(!weapon)
  return notify_fail("没有这种兵器！\n");
  weapon->move(ob);
  message_vision("$N从兵器架上拿下了一个"+weapon->name()+"。\n",ob);
  return 1;
}

void end_fight(object killer,object victim)
{
  if(victim->query("kee")<=0)
   victim->set("kee",1);
  if(victim->query("eff_kee")<=0)
   victim->set("eff_kee",1);
  if(victim->query("gin")<=0)
   victim->set("gin",1);
  if(victim->query("eff_gin")<=0)
   victim->set("eff_gin",1);
  
  message("system",HIR"【比武擂台】 :"NOR+HIG+"在本次比武中，"+killer->name()+HIG+
            "代表"+ORG_D->get_shili(killer)+"战胜了"+victim->name()+HIG+",获得了胜利！\n"NOR,users());
  add_shili(killer,victim->query("max_pot")*2,victim->query("max_pot"));
  add("win_list/"+killer->query("shili/name"),1);
  save();
  return ;
}

int do_list()
{
  int i;
  mapping wins;
  string *wins_list;
  string msg;
  object ob;
  ob=this_player();
  wins=query("win_list");
  if(!mapp(wins))
  return notify_fail("还没有进行任何比赛！\n");
  wins_list=keys(wins);
  msg="━━━━━━━━━━━━━━━━━━━━━━━━━━━\n";
  msg+=HIR"                   天下英雄比武大会                   \n"NOR;
  msg+="比武大会目前胜负情况：\n\n\n";
  for(i=0;i<sizeof(wins_list);i++){
  	
  msg+=sprintf("%-10s  获胜次数：%d\n",
  ORG_D->get_board_shili(wins_list[i]),wins[wins_list[i]]);}
  msg+="━━━━━━━━━━━━━━━━━━━━━━━━━━━\n";
  ob->start_more(msg);
  return 1;
}

int valid_leave(object ob,string dir)
{
  object *inv;
  int i;
  
  inv=all_inventory(ob);
  if(dir=="eastdown"||dir=="westdown"||dir=="southdown"){
    for(i=0;i<sizeof(inv);i++){
      if(inv[i]->query("leitai_weapon"))
       destruct(inv[i]);}}
  return ::valid_leave(ob,dir);
}

int do_biwu(string arg)
{
  object ob;
  string id1,id2;
  object target1,target2;
  ob=this_player();
  
  if((!arg||sscanf(arg,"%s with %s",id1,id2)!=2)&&
     wizardp(ob))
  return notify_fail("请使用 biwu id1 with id2 格式。\n");
  if(!wizardp(ob)) return 0;
  if(!objectp(target1=present(id1,environment(ob))))
  return notify_fail("这里没有"+id1+"！\n");
  if(!objectp(target2=present(id2,environment(ob))))
  return notify_fail("这里没有"+id2+"！\n");
  message("vision",YEL"【比武擂台】："+target1->name()+NOR+YEL+
                  "和"+target2->name()+NOR+YEL+"在擂台现在开始比武！\n"NOR,
                  users());
  target1->fight_ob(target2);
  target2->fight_ob(target1);
  return 1;
}

int do_clear()
{
  object ob;
  ob=this_player();
  
  if(!wizardp(ob)) return 0;
  if(!query("win_list"))
  return notify_fail("目前还没有比武成绩。\n");
  tell_object(ob,"你删掉了本次比武的成绩。\n");
  delete("win_list");
  save();
  return 1;
}