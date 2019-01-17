// 大唐双龙传


inherit NPC;

void create()
{
  set_name("粮店老板", ({"liangdian laoban","laoban"}));
  set("long","这是一名粮店老板。\n");
  set("gender", "男性");
  set("age",40);
  set("combat_exp", 200000);

  set_skill("unarmed", 10);
  set_skill("dodge", 40);
  set_skill("parry", 30);
  
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
     command("say 这年头，在长安做生意是最稳妥了。");
     break;
    case 1:
     command("say 来买点粮吧？我这里的粮很好的。");
   }
   
}

