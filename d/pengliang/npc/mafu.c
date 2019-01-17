
inherit NPC;

void create()
{
   set_name("马夫",({ "ma fu","fu" }) );
   set("gender", "男性" );
   set("age", 32);
   set("long", "这是一名马夫。\n");
       
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
    command("say 看我这里的马，是不是养得很好？");
    break;
   case 1:
    command("say 我养的马仅次于飞马牧场，名列天下第二！");
  }
  
}