
inherit NPC;

void create()
{
   set_name("柳宗道",({ "liu zongdao","liu"}) );
        set("gender", "男性" );
        set("age", 40);
   set("long", "他就是飞马牧场的四大执事之二。\n");
       
   set("combat_exp",400000);
   set("str", 26);
   set("per", 22);
   set("attitude", "peaceful");
   set_skill("unarmed",130);
   set_skill("dodge",130);
   set_skill("parry",130);
   set_skill("babu-ganchan",130);
   
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
  
}

