
inherit NPC;

void create()
{
   set_name("弟子",({ "di zi","di","zi"}) );
        set("gender", "男性" );
        set("age", 32);
        set("target_id","####");
        set("long","这是石龙武馆的弟子，看起来非常威武。\n");
    setup();
   
}

void init()
{
   object ob;
   
   ob=this_player();
   if(!ob) return;
   remove_call_out("welcome");
   call_out("welcome",1,ob);
}

void welcome(object ob)
{
   if(!ob) return;
   
   if(environment(ob)!=environment())
   return;
   
   switch(random(3)){
   
   case 0:
    message_vision("$N朝$n笑道：快来石龙武馆报名吧！一定能让你学到武艺！\n",
    this_object(),ob);
    break;
   case 1:
     command("hi "+ob->query("id"));
     break;
   
   case 2:
     command("dtsl "+ob->query("id"));
    }
  return;
}

int accept_fight(object who)
{
   return 0;
}

void kill_ob(object ob)
{
  ob->remove_killer(this_object());
  command("bi "+ob->query("id"));
  return;
}