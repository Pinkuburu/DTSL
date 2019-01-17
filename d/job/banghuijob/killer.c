#include <job_money.h>
#include <ansi.h>
inherit NPC;
void create()
{
       set_name("蒙面人",({"pan tu","pan","tu"}));
       set("gender", "男性" );
       set("age", 32);
    set("combat_exp", 800000);
   set("str", 30);
   set("max_gin",2000);
   set("max_kee",2000);
   set("max_sen",2000);
   set("max_force",3000);
   set("force",3000);
 setup();
 add_money("silver",40+random(10));
}

void die()
{
  object ob;
  int exp,sil;
  ob=this_object()->query_temp("last_damage_from");
  if(!objectp(ob)) return ::die();
  if(ob->query("id")==this_object()->query("job/p_id")){
  message_vision(HIR"$N惨嚎一声，叫道：老子二十年后还是一条好汉！\n"NOR,this_object());
  exp=180+random(20);
  sil=ob->query("max_pot")/3;
  add_shili(ob,exp,sil);
  ob->add("potential",random(10));
  if(ob->query("potential")>ob->query("max_pot"))
	ob->set("potential",ob->query("max_pot"));
  tell_object(ob,"这次行动你为帮会赢得了"+HIW+chinese_number(exp)+NOR+
              "点经验,"+MONEY_D->money_str(sil)+"。\n");
  tell_object(ob,"你的潜能也提高了！\n");
  ob->set("busy_time",time());
  ob->delete_temp("bhjob");}
  return ::die();
}

int kill_object(object killer,object victim)
{
  message_vision("$N狂笑道：我终于杀了一个！哈哈！！\n",killer);
  message_vision("$N身形一晃，踪迹不见！\n",killer);
  destruct(killer);
  return 1;
}

void init()
{
  set("last",time());
}

int clear()
{
  if(time()-query("last")<300)
  return 0;
  if(!query("no_msg")){
  message_vision("$N匆匆地走了。\n",this_object());
  set("no_msg",1);
  call_out("dispear",1);}
  return 1;
}

void dispear()
{
   destruct(this_object());
   return;
}

int chat()
{
  if(clear()) return 1;
  return ::chat();
}