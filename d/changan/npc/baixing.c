// 大唐双龙传


inherit NPC;

void create()
{
  set_name("百姓", ({"bai xing","xing"}));
  set("long","这是一个长安的百姓。\n");
  set("gender", "男性");
  set("combat_exp", 90000);

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
     command("say 现在天下混乱，也就数我们长安是最好的了！");
     break;
    case 1:
     command("say 李世民雄才伟略，我希望他能当上皇帝。");
   }
   
}

