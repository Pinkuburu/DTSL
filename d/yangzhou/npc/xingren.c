
inherit NPC;

void create()
{
   set_name("行人",({ "xing ren","xing","ren"}) );
   set("gender", "男性" );
   set("age", 30);
		
   set("long", "这是一位要去扬州的行人。\n");
       
   set("combat_exp", 100000);
   set("str", 26);
   
   set_skill("unarmed",50);
   set_skill("dodge",50);
   set_skill("parry",50);
  
   set("chat_chance",10);
   set("chat_msg",({
     "行人说道：据说扬州十分繁华，今天要去看看。\n",
     "行人向前看看：终于看到扬州的城门了！\n",
    }));
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
 
}

