
inherit NPC;

void create()
{
   set_name("尤贵",({ "you gui","you","gui"}) );
        set("gender", "男性" );
        set("age",31);
        set("nickname","胖刺客");
        set("long","这就是海沙帮中的尤贵，他近来在余航一带活动。\n");
               
        set("combat_exp",250000);
        set_skill("parry",130);
        set_skill("dodge",130);
        set_skill("force",130);
        set_skill("sword",130);
        set_skill("levelone-sword",130);
        set_skill("babu-ganchan",140);
        add_money("coin",20);
        set("shili/name","haisha_b");
        set("chat_chance_combat",30);
        set("chat_msg_combat",({
        	(:apply_action,"levelone-sword",1,"damage":),
             }));
    setup();
   carry_object(__DIR__"obj/cloth")->wear();
   carry_object(__DIR__"obj/sword")->wield();
  
}

