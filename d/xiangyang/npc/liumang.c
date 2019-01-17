
inherit NPC;

void create()
{
   set_name("流氓",({ "liu mang","liu","mang"}) );
        set("gender", "男性" );
        set("age", 22);
		
   set("long", "这是襄阳城整天无所事事的流氓。\n");
       
   set("combat_exp", 5000);
   set("str", 20);
   set("per", 25);
   set_skill("unarmed",20);
   set_skill("dodge",20);
   set_skill("parry",20);
  set("attitude", "peaceful");
  set("chat_chance",30);
  set("chat_msg",({
	  "流氓哼道：老子天不怕，地不怕，谁能管得了我？\n",
	  "流氓大声喊道：喂，你总是在这里，是不是找麻烦?\n",
	  "流氓嘿嘿笑道：有没有漂亮的妞啊，介绍一个？\n",
	  "流氓冷冷地看了看周围.\n",
  }));

   setup();
   carry_object(__DIR__"obj/cloth")->wear();
 
}

