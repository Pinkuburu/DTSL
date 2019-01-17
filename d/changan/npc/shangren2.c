
inherit NPC;

void create()
{
   set_name("波斯商人",({ "bosi shangren","shangren"}) );
        set("gender", "男性" );
        set("age", 32);
   set("long", "这是一位在长安城做生意的波斯商人。\n");
       
   set("combat_exp", 200000);
   
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
  
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
   if(!ob) return;
   if(environment(ob)!=environment(this_object()))
   return;
   
   switch(random(2)){
    case 0:
     command("say 请真主保佑我生意顺利，发大财！");
     break;
    case 1:
     command("say 我每天都来这里，希望真主能保佑我。");
   }
   
}

