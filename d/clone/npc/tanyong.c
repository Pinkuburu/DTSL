
inherit NPC;

void create()
{
   set_name("谭勇",({ "tan yong","tan","yong"}) );
        set("gender", "男性" );
        set("age",31);
        set("long","这就是海沙帮中的谭勇，他近来负责余航的贩盐生意。\n");
               
        set("combat_exp",80000);
        set_skill("parry",80);
        set_skill("dodge",80);
        set_skill("force",80);
        set_skill("blade",80);
        set_skill("whdmdao",90);
        set_skill("babu-ganchan",80);
        add_money("coin",20);
        set("shili/name","haisha_b");
    setup();
   carry_object(__DIR__"obj/cloth")->wear();
   carry_object(__DIR__"obj/blade")->wield();
  
}

