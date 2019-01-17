
inherit NPC;

void create()
{
   set_name("伙计",({ "huo ji","huo","ji"}) );
        set("gender", "男性" );
        set("age", 20+random(10));
		
   set("long", "这是裁缝店的伙计。\n");
       
   set("combat_exp", 50000);
   
   set_skill("unarmed",20);
   set_skill("dodge",20);
   set_skill("parry",20);
  
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
      command("say 欢迎光临，小店的服装可都是提供给皇宫大内用的哦！");
      break;
     case 1:
      command("say 我们这里的衣服手工上乘，包您满意！");
   }
   
}