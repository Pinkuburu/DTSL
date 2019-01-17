
inherit NPC;

#include <job_money.h>

void create()
{
     
   set_name("杀手",({"killer"}));
        set("gender", "男性" );
        set("nickname","无影无踪");
        set("age", 24);
   set("long", "这是一名职业杀手，宋家堡雇佣他刺杀某些人。\n");
       
   set("combat_exp", 70000);
   set_skill("cuff",60);
   set_skill("finger",60);
   set_skill("parry",60);
   set_skill("dodge",60);
   set_skill("force",60);
   
   set_skill("linglong-yuquan",60);
   set_skill("dujie-zhi",60);
   set_skill("anxiang-fuying",60);
   
   set("force",200);
   set("max_force",200);
   create_family("宋家堡",7,"弟子");
  
   setup();
   
}


int set_status(object ob)
{
   set("target_id",ob->query("id"));
   set("last",time());
   
   set("combat_exp",ob->query("combat_exp"));
   copy_hp_item(ob,this_object(),"gin");
   copy_hp_item(ob,this_object(),"kee");
   copy_hp_item(ob,this_object(),"sen");
   
   set_all_skill(this_object(),ob->query("max_pot")-100);
   
   return 1;
}

int clear()
{
  if(time()-query("last")<500)
  return 0;
  if(!query("no_msg")){
  message_vision("$N左右看了看，匆匆地跑了。\n",this_object());
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

