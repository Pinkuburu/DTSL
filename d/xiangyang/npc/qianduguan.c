
inherit NPC;

void create()
{
   set_name("钱独关",({ "qian duguan","qian"}) );
        set("gender", "男性" );
        set("age", 32);
   set("long", "这是钱独关,据说他是阴癸派的人。\n");
       
   set("combat_exp",200000);
   set("attitude", "peaceful");
   set_skill("unarmed",100);
   set_skill("dodge",100);
   set_skill("parry",100);
   set_skill("force",100);
   set_skill("strike",100);
   set_skill("cuff",100);
  setup();
   carry_object(__DIR__"obj/cloth")->wear();
  
}

