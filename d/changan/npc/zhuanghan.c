// 大唐双龙传


inherit NPC;

void create()
{
  set_name("壮汗", ({"zhuang han","han"}));
  set("long","这是一个壮汗，看起来十分强壮。\n");
  set("gender", "男性");
  set("combat_exp",200000);

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
     command("say 我要努力学习武艺，为长安出一份力！");
     break;
    case 1:
     command("say 我的身体不错，不过就是没什么学问。");
   }
   
}

