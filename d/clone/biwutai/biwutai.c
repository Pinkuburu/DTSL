
inherit ROOM;
#include <ansi.h>
#include <job_money.h>
int filter_user(object ob);
mapping d_member=([
 "yingui":"阴癸派","chanyuan":"静念禅院","songjia":"宋家堡","dongming":"东溟派","yijian":"弈剑派",
 "huajian":"花间派","jingzhai":"慈航静斋","feima":"飞马牧场","haisha":"海沙帮","tujue":"突厥",
 "duzun":"独尊堡","lifa":"李  阀","dajiang":"大江联",]);
void create()	
{
	set("short", HIR"比武台"NOR);
	set("long", @LONG
如果文的解决不了，就只好来武的了。这里是比武台，在这
里可以安全的较量，这里的死亡是非有效死亡。而且这里的
比武是现场直播的。这里有兵器架(jia)，你可以从上面取
(qu)兵器。
LONG);
    set("exits", ([
	        "east" : __DIR__"meeting_room",
 	]));
 	set("no_death",1);
 	set("no_sleep",1);
 	set("no_channel","还是好好比武吧！\n");
 	set("no_get",1);
 	set("no_quit",1);
 	set("broadcast",1);
 	set("end_fight",1);
 	set("item_desc",([
 	"jia":"这是一个兵器架，上面有刀(blade)\n"+
 	      "剑(sword)、锤(hammer)、匕首(dagger)、"+
 	      "枪(fork)、斧子(axe).你可以qu xx来拿兵器。\n",
 	      ]));
      setup();
	
}

void init()
{
add_action("do_qu","qu");
}	

int broadcast(string str)
{
  tell_room("/d/yangzhou/kantai",HIR"【比武擂台】 :"NOR+str);
  return 1;
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
  message_vision("$N从兵器架上拿下了一个"+weapon->name()+"\n",ob);
  return 1;
}

void end_fight(object killer,object victim)
{
  object *usr,*ob,here;int i;
  usr=filter_array(users(),"filter_user",this_object());
  message("system",HIR"【比武擂台】 :"NOR+HIG+"在本次比武中，"+killer->name()+
            "战胜了"+victim->name()+",获得了胜利！\n",usr);
  add_shili(killer,victim->query("max_pot")*2,victim->query("max_pot"));
  this_object()->add("win_count/"+killer->query("clean/register_leitai"),1);
  victim->set("clean/fail",1);
  if(this_object()->query("win_count/"+killer->query("clean/register_leitai"))>=3){
   message("system",HIR"【比武擂台】 :"NOR+HIG+"在本次比武中，"+d_member[killer->query("clean/register_leitai")]+
        "战胜了"+d_member[victim->query("clean/register_leitai")]+"!\n"NOR,users());
   __DIR__"meeting_room"->delete("dengji");
   __DIR__"meeting_room"->delete("zhuce");
   killer->delete("clean");
   victim->delete("clean");
   this_object()->delete("win_count");
   here=load_object(__DIR__"meeting_room");
   ob=all_inventory(here);
   for(i=0;i<sizeof(ob);i++)
   if(interactive(ob[i]))
     ob[i]->delete("clean");
   }
   
  return ;
}

int valid_leave(object ob,string dir)
{
  __DIR__"meeting_room"->add("member_count",-1);
  return ::valid_leave(ob,dir);
}