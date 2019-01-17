
inherit NPC;
#include <ansi.h>


void create()
{
   set_name("老虎",({ "lao hu","hu","tigger"}) );
        set("race", "野兽" );
     set("long", "这是一只老虎，看起来非常凶残。\n");
	 set("verbs",({"bite","claw"}));
     set("limbs",({"头","尾巴","胸部","腹部"}));
     setup();

}

int set_status(object ob)
{
  set("target_id",ob->query("id"));
  set("last",time());
  return 1;
}

int clear()
{
  if(time()-query("last")<300)
  return 0;
  if(!query("no_msg")){
  message_vision("$N长啸一声，晃晃头走了。\n",this_object());
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
   
   if(clear())
   return 1;
   
   return ::chat();
}

void die()
{
   object ob;
   
   ob=query_temp("last_damage_from");
   if(!ob||
      ob->query("id")!=query("target_id")
     )
     return ::die();
     ob->set_temp("bai_songfaliang/action2",1);
     ob->delete_temp("bai_songfaliang/action1");
     return ::die();
}