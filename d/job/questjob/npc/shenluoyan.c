
inherit NPC;

void create()
{
   set_name("沈落雁",({ "shen luoyan","shen"}) );
        set("gender", "女性" );
        set("age", 26);
		
   set("long", "这是沈落雁，她乃李密手下第一谋士。\n");
       
   set("combat_exp",600000);
   set_skill("sword",182);
   set_skill("dodge",182);
   set_skill("force",182);
   set_skill("parry",182);
   set_skill("leveltwo-sword",182);
   set_skill("niaozong-shu",182);
   
   set("max_kee",1000);
   set("max_sen",1000);
   set("max_force",1000);
   set("force",1000);
   
   set("str", 20);
   set("per", 26);
   set("inquiry",([
      "寇仲":"我和他是敌又是友，他可真是让我可气。\n",
      "徐子陵":"他的机智不下于寇仲，这两个人最让我头疼了。\n",
      "李密":"这是我的主子，有什么事要我转告吗？\n",
      ]));
   setup();
  carry_object(__DIR__"obj/changjian")->wield();
}

