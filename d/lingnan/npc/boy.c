
inherit NPC;

void create()
{
   set_name("男弟子",({ "boy" }) );
        set("gender", "男性" );
        set("age", 20);
   set("long", "这是宋家堡的弟子，武功也是不俗。\n");
       
   set("combat_exp", 50000);
   set_skill("blade",30);
   set_skill("tiandao-bajue",30);
   set_skill("dodge",30);
   set_skill("force",30);
   set("force",200);
   create_family("宋家堡",7,"弟子");
   set("chat_chance",20);
   set("chat_msg",({
   "男弟子说道：谁不知道我们宋家堡称雄武林，独霸岭南？\n",
   "男弟子笑道：天下么，还不早晚是我们宋家的？\n",
   "男弟子伸了伸胳膊：唉，天天在这里守大门，真是没什么意思啊！\n"
   }));
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
   carry_object(__DIR__"obj/blade")->wield();
  
}

