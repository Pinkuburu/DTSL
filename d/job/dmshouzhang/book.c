
inherit ITEM;
#include <job_money.h>
#include <ansi.h>

string *dirs1=({
"/d/hengshan","/d/suiye"
});

string *dirs2=({
"/d/huashan","/d/emeishan","/d/taishan"
});

int do_shou(string arg);

void create()
{
   set_name("账本",({"zhang ben","zhang","ben"}));
   set_weight(10);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("no_drop",1);
     set("unit", "个");
   }
   setup();
}

void init()
{
  add_action("do_shou","shouzhang");
}

int do_shou(string arg)
{
  object ob,target;
  object killer;
  string name;
  string *dirs;
  
  ob=this_player();
  
  if(!arg||sscanf(arg,"with %s",name)!=1)
  return notify_fail("请使用shouzhang with xxx 向 xxx收账。\n");
  
  if(!objectp(target=present(name,environment(ob))))
  return notify_fail("你身边没有这个人。\n");
  if(userp(target))
  return notify_fail("对方根本不理会你。\n");
  if(!living(target))
  return notify_fail("看起楚，对方是活人吗？\n");
  if(query("dm_shouzhang_target")!=base_name(target))
  return notify_fail(target->name()+"眼睛一横，找我收账？你走错地方了吧？\n");
  
  if(query("dm_shouzhang_ok"))
  return notify_fail("我不是已经写完了，还是请快回去交差吧！\n");
  
 
  if(ob->query("combat_exp")<500000){
   message_vision("$N满脸含笑：东溟给了我这么大帮助，怎么会忘记交账呢？\n",target);
   message_vision("$N连忙在账本上写了几个字。\n",target);
   set("dm_shouzhang_ok",1);
   return 1;}
  //以下是200K或600K以后出杀手了。
  if(ob->query_temp("have_killed_killer")){
   ob->delete_temp("have_killed_killer");
   message_vision("$N满脸含笑：我怎么敢和东溟作对呢？我这就写！\n",target);
   message_vision("$N连忙在账本上写了几个字。\n",target);
   set("dm_shouzhang_ok",1);
   return 1;}
  
   if(query("fighting")){
  
    if(ob->query("combat_exp")<1000000)
     return notify_fail("加油！加油！\n");
    else
     return notify_fail(target->name()+"朝你冷笑道：你到底有没有这个胆量？\n");
   }
  
  set("fighting",1);
  
  if(ob->query("combat_exp")<1000000){
  
  killer=new(__DIR__"killer"); 
  killer->set_status(ob); 
  killer->move(environment(ob));
  message_vision(HIW"$N眼睛一横：哼，三天两头就来收账，还让不让我们活了？！\n"+
  "要钱没有，要命一条！！\n"NOR,target);
  tell_object(ob,target->name()+"喊道：护卫，给我杀了这个小王八蛋！！\n");
  message_vision("$N快步跑了进来！\n",killer);
  killer->kill_ob(ob);
  ob->add_temp_array("job_temp_killer",killer);
  return 1;
  }
  
  killer=new(__DIR__"killer"); 
  killer->set_status(ob);
  
  if(ob->query("combat_exp")<=1000000)
   dirs=dirs1;
  else
   dirs=dirs1+dirs2;
  
  if(!random_place(killer,dirs))
   return notify_fail(target->name()+"惊慌道：等，等一下... ...\n");
  if(!environment(killer))
   return notify_fail(target->name()+"惊慌道：等，等一下... ...\n");
  
  ob->add_temp_array("job_temp_killer",killer);//记入killer变量，
                                               //如果任务放弃或完成或quit.
                                               //此物件清除。
  tell_object(ob,target->name()+"朝你冷笑道：想来我这里收账也可以！\n"+
    "除非你能杀死我这里的最高护卫"+killer->name()+"！\n"+
    "他现在在"+MISC_D->find_place(environment(killer))+"，看你有没有这个胆量了！\n");
  
  return 1;

}
 
  
