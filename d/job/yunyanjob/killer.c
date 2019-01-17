
inherit JOBNPC;
#include <ansi.h>
#include <job_money.h>

void create()
{
   set_name("强盗",({ "qiang dao","qiang","dao"}) );
        set("gender", "男性" );
        set("age",30);
		
   set("long", "这是个专门抢劫官府盐车的强盗。\n");
       
   set("combat_exp", 200000);
   set("str", 10+random(20));
   set("cor", 10+random(20));
   set_skill("force",20);
   set("force",800);
   set("max_force",800);

   setup();
   add_money("silver",1);
}

int set_status(object me)
{
	JOBNPC_D->set_yunyanjob_killer(this_object(),me);
	return 1;	
}


int clear()
{
  if(time()-query("last")<4000)
  return 0;
  if(!query("no_msg")){
  message_vision("$N匆匆地走了。\n",this_object());
  set("no_msg",1);
  call_out("dispear",1);}
  return 1;
}

void die()
{
    object ob;
    ob=query_temp("last_damage_from");
    if(ob)
    if(query("target_id")==ob->query("id"))
      ob->add_temp("need_killer_flags",1);
    return ::die();
}

void dispear()
{
     destruct(this_object());
   return;
}

int chat()
{
   
   if(clear())
   return 1;
   
   return ::chat();
}

