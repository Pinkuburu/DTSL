// 大唐双龙传


inherit NPC;

void create()
{
  set_name("酒保", ({"jiu bao","jiu","bao"}));
  set("long","这是一名酒保。\n");
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
     command("say 我们酒仓的酒，那绝对是长安第一位的！");
     break;
    case 1:
     command("say 整天在这里呆着，弄得我也晕头晕脑了。");
   }
   
}

