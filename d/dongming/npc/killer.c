
inherit NPC;

string *name=({
"天","tian",
"刚","gang",
"猛","meng",
"壮","zhuang",
"强","qiang",
"刀","dao"
});

void create()
{
   int i;
   
   i=random(sizeof(name));
   if(i%2!=0)
   i--;
   
   set_name("宇文"+name[i],({ "yuwen "+name[i+1],"yuwen",name[i+1]}) );
   set("gender", "男性" );
   set("long", "这是宇文阀的弟子。\n");
       
   set("combat_exp",500000);
   set_skill("dodge",140);
   set_skill("parry",140);
   set_skill("force",140);
   set("max_force",1000);
   set("force",1000);
   setup();
   
}

void die()
{
	object ob;
	
	ob=query_temp("last_damage_from");
	if(!ob||
	   query("target_id")!=ob->query("id")
	  )
	return ::die();
	command("haha");
	command("say 东溟的账本已经被人毁掉了，谁也拿不到了！");
	ob->set_temp("bai_shanwanjing/ok",1);
	ob->delete_temp("bai_shanwanjing/action2");
	ob->delete_temp("bai_shanwanjing/action1");
	
	return ::die();
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
  message_vision("$N左右看了看，鬼鬼祟祟地跑了。\n",this_object());
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


