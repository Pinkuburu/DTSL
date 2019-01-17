
inherit NPC;

void create()
{
   set_name("民工",({ "min gong","gong" }) );
   set("gender", "男性" );
   set("age", 32);
   set("long", "这是一名民工。\n");
       
   set("combat_exp",200000);
 
   setup();
 
}

void init()
{
  object ob;
  
  ob=this_player();
  
  if(!ob||is_fighting()) return;
  
  remove_call_out("welcome");
  call_out("welcome",1,ob);
  
}

void welcome(object ob)
{
  if(!ob||environment(ob)!=environment(this_object())) return;
  
  switch(random(2)){
   case 0:
    command("say 我们要建设最坚固的彭梁，守护少帅军！");
    break;
   case 1:
    command("say 我坚信少帅军会夺得天下！");
  }
  
}